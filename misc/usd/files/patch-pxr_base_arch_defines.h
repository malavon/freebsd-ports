--- pxr/base/arch/defines.h.orig	2022-02-18 21:49:09 UTC
+++ pxr/base/arch/defines.h
@@ -34,6 +34,8 @@ PXR_NAMESPACE_OPEN_SCOPE
 
 #if defined(__linux__)
 #define ARCH_OS_LINUX
+#elif defined(__FreeBSD__)
+#define ARCH_OS_FREEBSD
 #elif defined(__APPLE__)
 #include "TargetConditionals.h"
 #define ARCH_OS_DARWIN
@@ -93,7 +95,7 @@ PXR_NAMESPACE_OPEN_SCOPE
 //
 
 // Only use the GNU STL extensions on Linux when using gcc.
-#if defined(ARCH_OS_LINUX) && defined(ARCH_COMPILER_GCC)
+#if defined(ARCH_OS_LINUX) || defined(ARCH_OS_FREEBSD) && defined(ARCH_COMPILER_GCC)
 #define ARCH_HAS_GNU_STL_EXTENSIONS
 #endif
 
@@ -104,7 +106,7 @@ PXR_NAMESPACE_OPEN_SCOPE
 #endif
 
 // The MAP_POPULATE flag for mmap calls only exists on Linux platforms.
-#if defined(ARCH_OS_LINUX)
+#if defined(ARCH_OS_LINUX) || defined(ARCH_OS_FREEBSD)
 #define ARCH_HAS_MMAP_MAP_POPULATE
 #endif
 
