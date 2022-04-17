--- pxr/base/tf/pch.h.orig	2022-02-18 21:49:09 UTC
+++ pxr/base/tf/pch.h
@@ -39,7 +39,7 @@
 #include <boost/preprocessor/config/limits.hpp>
 #include <mach/mach_time.h>
 #endif
-#if defined(ARCH_OS_LINUX)
+#if defined(ARCH_OS_LINUX) || defined(ARCH_OS_FREEBSD)
 #include <dirent.h>
 #include <glob.h>
 #include <sys/param.h>
