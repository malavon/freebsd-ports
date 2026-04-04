--- src/mutex.h.orig	2007-06-11 15:16:23 UTC
+++ src/mutex.h
@@ -58,7 +58,7 @@ class mutex_locker
 class mutex_locker
 {
  protected:
-	mutex& mymutex;
+	::mutex& mymutex;
  private:
 	mutex_locker();
 	mutex_locker(const mutex_locker& );
@@ -67,7 +67,7 @@ class mutex_locker
 	/// create mutex locker
 	///@param mtx - mutex to lock
 	///@note will instantly lock the mutex that was given as parameter
-	mutex_locker(mutex& mtx) : mymutex(mtx) { mymutex.lock(); }
+	mutex_locker(::mutex& mtx) : mymutex(mtx) { mymutex.lock(); }
 
 	/// destroy mutex locker
 	///@note will unlock the mutex that was given to the constructor
