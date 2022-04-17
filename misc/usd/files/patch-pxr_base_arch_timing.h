--- pxr/base/arch/timing.h.orig	2022-02-18 21:49:09 UTC
+++ pxr/base/arch/timing.h
@@ -36,7 +36,7 @@
 /// \addtogroup group_arch_SystemFunctions
 ///@{
 
-#if defined(ARCH_OS_LINUX) && defined(ARCH_CPU_INTEL)
+#if defined(ARCH_OS_LINUX) || defined(ARCH_OS_FREEBSD) && defined(ARCH_CPU_INTEL)
 #include <x86intrin.h>
 #elif defined(ARCH_OS_DARWIN)
 #include <mach/mach_time.h>
