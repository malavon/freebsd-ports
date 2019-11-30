--- support/install-share.py.orig	2019-11-30 11:47:08 UTC
+++ support/install-share.py
@@ -28,17 +28,20 @@ def cleanup(support_dir):
 
 
 def get_install_path(argv):
-    if len(argv) != 2:
+    if len(argv) != 3:
         print('ERROR: Unexpected number of arguments.')
         sys.exit(1)
     else:
         return argv[1]
 
+def get_archive_path(argv):
+	return argv[2]
 
 def main():
     install_path = get_install_path(sys.argv)
     support_dir = os.path.join(install_path, 'share', 'retdec', 'support')
-    arch_path = os.path.join(support_dir, arch_name)
+    archive_dir = get_archive_path(sys.argv)
+    arch_path = os.path.join(archive_dir, 'support', arch_name)
 
     # Share directory exists.
     if os.path.exists(support_dir):
@@ -56,16 +59,6 @@ def main():
 
     # Make sure destination directory exists.
     os.makedirs(support_dir, exist_ok=True)
-
-    # Download archive
-    arch_url = 'https://github.com/avast/retdec-support/releases/download/%s/%s' % (version, arch_name)
-    print('Downloading archive from %s ...' % arch_url)
-    try:
-        urllib.request.urlretrieve(arch_url, arch_path)
-    except (urllib.request.HTTPError, urllib.request.URLError) as ex:
-        print('ERROR: download failed:', ex)
-        cleanup(support_dir)
-        sys.exit(1)
 
     # Compute hash of the downloaded archive.
     print('Verifying archive\'s checksum ...')
