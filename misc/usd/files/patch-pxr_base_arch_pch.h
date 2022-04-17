--- pxr/base/arch/pch.h.orig	2022-02-18 21:49:09 UTC
+++ pxr/base/arch/pch.h
@@ -44,7 +44,7 @@
 #include <mach-o/swap.h>
 #include <mach/mach_time.h>
 #endif
-#if defined(ARCH_OS_LINUX)
+#if defined(ARCH_OS_LINUX) || defined(ARCH_OS_FREEBSD)
 #include <csignal>
 #include <dlfcn.h>
 #include <glob.h>
