--- pxr/imaging/plugin/hdPrmanLoader/rendererPlugin.cpp.orig	2022-02-18 21:49:09 UTC
+++ pxr/imaging/plugin/hdPrmanLoader/rendererPlugin.cpp
@@ -47,7 +47,7 @@ static struct HdPrmanLoader
 {
     static void Load();
     ~HdPrmanLoader();
-#if defined(ARCH_OS_LINUX) || defined(ARCH_OS_DARWIN)
+#if defined(ARCH_OS_LINUX) || defined(ARCH_OS_FREEBSD) || defined(ARCH_OS_DARWIN)
     void* libprman = nullptr;
 #endif
     void* hdPrman = nullptr;
@@ -71,7 +71,7 @@ HdPrmanLoader::Load()
         return;
     }
 
-#if defined(ARCH_OS_LINUX) || defined(ARCH_OS_DARWIN)
+#if defined(ARCH_OS_LINUX) || defined(ARCH_OS_FREEBSD) || defined(ARCH_OS_DARWIN)
     // Open $RMANTREE/lib/libprman.so into the global namespace
     const std::string libprmanPath =
         TfStringCatPaths(rmantree, "lib/libprman" ARCH_LIBRARY_SUFFIX);
@@ -135,7 +135,7 @@ HdPrmanLoader::~HdPrmanLoader()
         ArchLibraryClose(hdPrman);
         hdPrman = nullptr;
     }
-#if defined(ARCH_OS_LINUX) || defined(ARCH_OS_DARWIN)
+#if defined(ARCH_OS_LINUX) || defined(ARCH_OS_FREEBSD) || defined(ARCH_OS_DARWIN)
     if (libprman) {
         ArchLibraryClose(libprman);
         libprman = nullptr;
