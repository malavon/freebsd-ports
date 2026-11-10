--- CMake/FindQwt.cmake.orig	2026-11-10 10:47:51 UTC
+++ CMake/FindQwt.cmake
@@ -43,7 +43,7 @@ find_library(QWT_LIBRARY NAMES ${QWT_LIBRARY_NAMES}
 find_path(QWT_INCLUDE_DIR NAMES qwt.h
   PATH_SUFFIXES include lib/qwt.framework/Headers ${QWT_PATH_SUFFIXES})
 find_library(QWT_LIBRARY NAMES ${QWT_LIBRARY_NAMES}
-  PATH_SUFFIXES lib ${QWT_PATH_SUFFIXES})
+  PATH_SUFFIXES lib ${QWT_PATH_SUFFIXES} PATHS /usr/local/lib/qt6) # TODO
 
   message(WARNING "${QWT_INCLUDE_DIR}  ${QWT_LIBRARY}")
 
