--- pxr/usd/usdRender/pch.h.orig	2022-02-18 21:49:09 UTC
+++ pxr/usd/usdRender/pch.h
@@ -30,7 +30,7 @@
 #if defined(ARCH_OS_DARWIN)
 #include <mach/mach_time.h>
 #endif
-#if defined(ARCH_OS_LINUX)
+#if defined(ARCH_OS_LINUX) || defined(ARCH_OS_FREEBSD)
 #include <x86intrin.h>
 #endif
 #if defined(ARCH_OS_WINDOWS)
