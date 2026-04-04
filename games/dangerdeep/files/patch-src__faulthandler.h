--- src/faulthandler.h.orig	2007-06-11 18:29:30 UTC
+++ src/faulthandler.h
@@ -46,6 +46,7 @@ void install_segfault_handler()
 #include <execinfo.h>
 #include <stdio.h>
 #include <stdlib.h>
+#include <unistd.h>
 #include <cxxabi.h>      // Needed for __cxa_demangle
 #include <signal.h>
 #include <string>
