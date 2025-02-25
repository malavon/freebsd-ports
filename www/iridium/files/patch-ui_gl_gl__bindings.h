--- ui/gl/gl_bindings.h.orig	2023-03-13 07:33:08 UTC
+++ ui/gl/gl_bindings.h
@@ -37,7 +37,7 @@
 #include <GL/wglext.h>
 #elif BUILDFLAG(IS_APPLE)
 #include <OpenGL/OpenGL.h>
-#elif BUILDFLAG(IS_LINUX)
+#elif BUILDFLAG(IS_LINUX) || BUILDFLAG(IS_BSD)
 using Display = struct _XDisplay;
 using Bool = int;
 using Status = int;
