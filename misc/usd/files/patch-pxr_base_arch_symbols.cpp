--- pxr/base/arch/symbols.cpp.orig	2022-02-18 21:49:09 UTC
+++ pxr/base/arch/symbols.cpp
@@ -26,7 +26,7 @@
 #include "pxr/base/arch/fileSystem.h"
 #include "pxr/base/arch/symbols.h"
 #include "pxr/base/arch/defines.h"
-#if defined(ARCH_OS_LINUX)
+#if defined(ARCH_OS_LINUX) || defined(ARCH_OS_FREEBSD)
 #include <dlfcn.h>
 #elif defined(ARCH_OS_DARWIN)
 #include <dlfcn.h>
