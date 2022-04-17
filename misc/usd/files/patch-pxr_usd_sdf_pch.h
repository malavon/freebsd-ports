--- pxr/usd/sdf/pch.h.orig	2022-02-18 21:49:09 UTC
+++ pxr/usd/sdf/pch.h
@@ -35,7 +35,7 @@
 #include <unistd.h>
 #include <mach/mach_time.h>
 #endif
-#if defined(ARCH_OS_LINUX)
+#if defined(ARCH_OS_LINUX) || defined(ARCH_OS_FREEBSD)
 #include <glob.h>
 #include <limits.h>
 #include <sys/param.h>
