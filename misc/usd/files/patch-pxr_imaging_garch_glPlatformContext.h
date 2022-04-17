--- pxr/imaging/garch/glPlatformContext.h.orig	2022-02-18 21:49:09 UTC
+++ pxr/imaging/garch/glPlatformContext.h
@@ -32,7 +32,7 @@
 #include <cstddef>
 #include <functional>
 
-#if defined(ARCH_OS_LINUX)
+#if defined(ARCH_OS_LINUX) || defined(ARCH_OS_FREEBSD)
 
 #include "pxr/imaging/garch/glPlatformContextGLX.h"
 
