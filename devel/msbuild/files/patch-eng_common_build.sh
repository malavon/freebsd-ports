--- eng/common/build.sh.orig	2022-05-01 16:47:30 UTC
+++ eng/common/build.sh
@@ -197,10 +197,10 @@ function Build {
 }
 
 # Import custom tools configuration, if present in the repo.
-configure_toolset_script="$eng_root/configure-toolset.sh"
-if [[ -a "$configure_toolset_script" ]]; then
-  . "$configure_toolset_script"
-fi
+# configure_toolset_script="$eng_root/configure-toolset.sh"
+# if [[ -a "$configure_toolset_script" ]]; then
+#   . "$configure_toolset_script"
+# fi
 
 # TODO: https://github.com/dotnet/arcade/issues/1468
 # Temporary workaround to avoid breaking change.
