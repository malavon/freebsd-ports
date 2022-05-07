--- m4/libtool.m4.orig	2022-03-25 17:46:41 UTC
+++ m4/libtool.m4
@@ -1954,6 +1954,12 @@ else
     ])
     ;;
 
+  FreeBSD*)
+    lt_cv_dlopen="dlopen"
+    lt_cv_dlopen_libs=""
+    lt_cv_dlopen_self=yes
+    ;;
+
   tpf*)
     # Don't try to run any link tests for TPF.  We know it's impossible
     # because TPF is a cross-compiler, and we know how we open DSOs.
