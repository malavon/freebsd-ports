--- pxr/base/tf/testenv/mallocTag.cpp.orig	2022-02-18 21:49:09 UTC
+++ pxr/base/tf/testenv/mallocTag.cpp
@@ -35,7 +35,7 @@ PXR_NAMESPACE_USING_DIRECTIVE
 
 // The TfMallocTag code depends upon the Linux memory allocator, ptmalloc3.
 // Turning this test off for any other platforms for now.
-#if defined(ARCH_OS_LINUX)
+#if defined(ARCH_OS_LINUX) || defined(ARCH_OS_FREEBSD)
 
 using std::vector;
 using std::string;
