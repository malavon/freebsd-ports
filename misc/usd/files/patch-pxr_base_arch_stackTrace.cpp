--- pxr/base/arch/stackTrace.cpp.orig	2022-02-18 21:49:09 UTC
+++ pxr/base/arch/stackTrace.cpp
@@ -74,11 +74,11 @@
 /* Darwin/ppc did not do stack traces.  Darwin/i386 still 
    needs some work, this has been stubbed out for now.  */
 
-#if defined(ARCH_OS_LINUX)
+#if defined(ARCH_OS_LINUX) || defined(ARCH_OS_FREEBSD)
 #include <ucontext.h>
 #endif
 
-#if defined(ARCH_OS_LINUX) && defined(ARCH_BITS_64)
+#if defined(ARCH_OS_LINUX) || defined(ARCH_OS_FREEBSD) && defined(ARCH_BITS_64)
 #include <unwind.h>
 #endif
 
@@ -109,7 +109,7 @@ using namespace std;
 // total hack -- no idea if this will work if we die in malloc...
 typedef int (*ForkFunc)(void);
 ForkFunc Arch_nonLockingFork =
-#if defined(ARCH_OS_LINUX)
+#if defined(ARCH_OS_LINUX) || defined(ARCH_OS_FREEBSD)
     (ForkFunc)dlsym(RTLD_NEXT, "__libc_fork");
 #elif defined(ARCH_OS_DARWIN)
     NULL;
@@ -580,7 +580,7 @@ nonLockingFork()
 }
 #endif
 
-#if defined(ARCH_OS_LINUX)
+#if defined(ARCH_OS_LINUX) || defined(ARCH_OS_FREEBSD)
 static int
 nonLockingLinux__execve (const char *file,
                          char *const argv[],
