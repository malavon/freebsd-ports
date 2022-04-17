--- pxr/base/arch/mallocHook.cpp.orig	2022-02-18 21:49:09 UTC
+++ pxr/base/arch/mallocHook.cpp
@@ -177,7 +177,7 @@ ArchMallocHook::IsInitialized()
        _underlyingMemalignFunc || _underlyingFreeFunc;
 }
 
-#if defined(ARCH_OS_LINUX)
+#if defined(ARCH_OS_LINUX) || defined(ARCH_OS_FREEBSD)
 template <typename T>
 static bool _GetSymbol(T* addr, const char* name, string* errMsg) {
     if (void* symbol = dlsym(RTLD_DEFAULT, name)) {
