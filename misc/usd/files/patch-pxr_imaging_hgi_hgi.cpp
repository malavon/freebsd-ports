--- pxr/imaging/hgi/hgi.cpp.orig	2022-02-18 21:49:09 UTC
+++ pxr/imaging/hgi/hgi.cpp
@@ -65,7 +65,7 @@ _MakeNewPlatformDefaultHgi()
     PlugRegistry& plugReg = PlugRegistry::GetInstance();
 
     const char* hgiType = 
-        #if defined(ARCH_OS_LINUX)
+        #if defined(ARCH_OS_LINUX) || defined(ARCH_OS_FREEBSD)
             "HgiGL";
         #elif defined(ARCH_OS_DARWIN)
             "HgiMetal";
