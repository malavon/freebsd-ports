--- pxr/base/arch/assumptions.cpp.orig	2022-02-18 21:49:09 UTC
+++ pxr/base/arch/assumptions.cpp
@@ -35,6 +35,8 @@
 
 #if defined(ARCH_OS_LINUX)
 #include <unistd.h>
+#elif defined(ARCH_OS_FREEBSD)
+#include <sys/param.h>
 #elif defined(ARCH_OS_DARWIN)
 #include <sys/sysctl.h>
 #include <mach-o/arch.h>
@@ -50,6 +52,8 @@ Arch_ObtainCacheLineSize()
 {
 #if defined(ARCH_OS_LINUX)
     return sysconf(_SC_LEVEL1_DCACHE_LINESIZE);
+#elif defined(ARCH_OS_FREEBSD)
+    return CACHE_LINE_SIZE;
 #elif defined(ARCH_OS_DARWIN)
     size_t cacheLineSize = 0;
     size_t cacheLineSizeSize = sizeof(cacheLineSize);
