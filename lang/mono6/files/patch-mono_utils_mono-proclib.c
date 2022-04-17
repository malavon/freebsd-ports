--- mono/utils/mono-proclib.c.orig	2021-02-22 15:50:14.000000000 +0000
+++ mono/utils/mono-proclib.c
@@ -18,6 +18,7 @@
 #include <unistd.h>
 #endif
 #ifdef HAVE_SCHED_GETAFFINITY
+#define _WITH_CPU_SET_T
 #include <sched.h>
 #endif
 
