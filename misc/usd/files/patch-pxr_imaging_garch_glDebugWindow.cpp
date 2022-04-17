--- pxr/imaging/garch/glDebugWindow.cpp.orig	2022-02-18 21:49:09 UTC
+++ pxr/imaging/garch/glDebugWindow.cpp
@@ -26,7 +26,7 @@
 #include "pxr/imaging/garch/glPlatformDebugContext.h"
 #include "pxr/base/arch/defines.h"
 
-#if defined(ARCH_OS_LINUX)
+#if defined(ARCH_OS_LINUX) || defined(ARCH_OS_FREEBSD)
 #include "pxr/imaging/garch/glPlatformDebugWindowGLX.h"
 #elif defined(ARCH_OS_DARWIN)
 #include "pxr/imaging/garch/glPlatformDebugWindowDarwin.h"
