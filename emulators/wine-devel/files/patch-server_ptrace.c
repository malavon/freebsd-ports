--- server/ptrace.c.orig	2020-06-24 11:56:59 UTC
+++ server/ptrace.c
@@ -21,6 +21,8 @@
 #include "config.h"
 #include "wine/port.h"
 
+#undef HAVE_SYS_PTRACE_H
+
 #include <assert.h>
 #include <errno.h>
 #include <fcntl.h>
