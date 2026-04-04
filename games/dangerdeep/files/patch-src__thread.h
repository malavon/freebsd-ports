--- src/thread.h.orig	2007-06-11 15:16:23 UTC
+++ src/thread.h
@@ -25,6 +25,7 @@
 
 #include "condvar.h"
 #include <stdexcept>
+#include <string>
 #include <stdint.h>
 
 /// base class for threads.
@@ -47,7 +48,7 @@ class thread
 	struct SDL_Thread* thread_id;
 	bool thread_abort_request;
 	thread_state_t thread_state;
-	mutex thread_state_mutex;
+	::mutex thread_state_mutex;
 	condvar thread_start_cond;
 	std::string thread_error_message; // to pass exception texts via thread boundaries
 
