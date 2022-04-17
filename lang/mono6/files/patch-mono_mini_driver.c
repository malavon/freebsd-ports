--- mono/mini/driver.c.orig	2021-02-22 15:50:14.000000000 +0000
+++ mono/mini/driver.c
@@ -14,6 +14,8 @@
 #include <config.h>
 #include <signal.h>
 #if HAVE_SCHED_SETAFFINITY
+#include <sys/param.h>
+#define _WITH_CPU_SET_T
 #include <sched.h>
 #endif
 #ifdef HAVE_UNISTD_H
@@ -1881,6 +1883,9 @@ mono_set_use_smp (int use_smp)
 #if HAVE_SCHED_SETAFFINITY
 	if (!use_smp) {
 		unsigned long proc_mask = 1;
+#if defined(__FreeBSD_version) && __FreeBSD_version >= 1400042
+#undef GLIBC_BEFORE_2_3_4_SCHED_SETAFFINITY
+#endif
 #ifdef GLIBC_BEFORE_2_3_4_SCHED_SETAFFINITY
 		sched_setaffinity (getpid(), (gpointer)&proc_mask);
 #else
