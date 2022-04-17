--- pxr/imaging/garch/glPlatformDebugContext.cpp.orig	2022-02-18 21:49:09 UTC
+++ pxr/imaging/garch/glPlatformDebugContext.cpp
@@ -51,7 +51,7 @@ GarchGLPlatformDebugContext::IsEnabledCoreProfile()
 PXR_NAMESPACE_CLOSE_SCOPE
 
 ////////////////////////////////////////////////////////////
-#if defined(ARCH_OS_LINUX)
+#if defined(ARCH_OS_LINUX) || defined(ARCH_OS_FREEBSD)
 
 #include <GL/glx.h>
 #include <GL/glxtokens.h>
