--- pxr/base/arch/systemInfo.cpp.orig	2022-02-18 21:49:09 UTC
+++ pxr/base/arch/systemInfo.cpp
@@ -32,7 +32,7 @@
 #include <functional>
 #include <limits>
 
-#if defined(ARCH_OS_LINUX)
+#if defined(ARCH_OS_LINUX) || defined(ARCH_OS_FREEBSD)
 
     #include <sys/types.h>
     #include <sys/stat.h>
@@ -113,16 +113,23 @@ _DynamicSizedRead(
 std::string
 ArchGetExecutablePath()
 {
-#if defined(ARCH_OS_LINUX)
+#if defined(ARCH_OS_LINUX) || defined(ARCH_OS_FREEBSD)
 
+#if defined(ARCH_OS_LINUX)
     // On Linux the executable path is retrieved from the /proc/self/exe
     // symlink.
+#define SELF_PATHNAME "/proc/self/exe";
+#else
+    // On FreeBSD the executable path is retrieved from the /proc/curproc/file
+    // symlink.
+#define SELF_PATHNAME "/proc/curproc/file"
+#endif
     return
         _DynamicSizedRead(ARCH_PATH_MAX,
             [](char* buffer, size_t* size) {
-                const ssize_t n = readlink("/proc/self/exe", buffer, *size);
+                const ssize_t n = readlink(SELF_PATHNAME, buffer, *size);
                 if (n == -1) {
-                    ARCH_WARNING("Unable to read /proc/self/exe to obtain "
+                    ARCH_WARNING("Unable to read " SELF_PATHNAME " to obtain "
                                  "executable path");
                     *size = std::numeric_limits<size_t>::max();
                     return false;
@@ -130,7 +137,7 @@ ArchGetExecutablePath()
                 else if (static_cast<size_t>(n) >= *size) {
                     // Find out how much space we need.
                     struct stat sb;
-                    if (lstat("/proc/self/exe", &sb) == 0) {
+                    if (lstat(SELF_PATHNAME, &sb) == 0) {
                         *size = sb.st_size + 1;
                     }
                     else {
@@ -144,6 +151,7 @@ ArchGetExecutablePath()
                     return true;
                 }
             });
+#undef SELF_PATHNAME
 
 #elif defined(ARCH_OS_DARWIN)
 
@@ -192,7 +200,7 @@ ArchGetExecutablePath()
 int
 ArchGetPageSize()
 {
-#if defined(ARCH_OS_LINUX) || defined(ARCH_OS_DARWIN)
+#if defined(ARCH_OS_LINUX) || defined(ARCH_OS_FREEBSD) || defined(ARCH_OS_DARWIN)
     return sysconf(_SC_PAGE_SIZE);
 #elif defined(ARCH_OS_WINDOWS)
     SYSTEM_INFO info;
