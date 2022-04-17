--- pxr/base/tf/fileUtils.cpp.orig	2022-02-18 21:49:09 UTC
+++ pxr/base/tf/fileUtils.cpp
@@ -209,7 +209,7 @@ TfIsLink(string const& path)
 bool
 TfIsWritable(string const& path)
 {
-#if defined(ARCH_OS_LINUX)
+#if defined(ARCH_OS_LINUX) || defined(ARCH_OS_FREEBSD)
     // faccessat accounts for mount read-only status. For maintaining legacy
     // behavior, use faccessat instead of access so we can use the effective
     // UID instead of the real UID. 
