--- pxr/base/arch/debugger.cpp.orig	2022-02-18 21:49:09 UTC
+++ pxr/base/arch/debugger.cpp
@@ -31,7 +31,7 @@
 #include "pxr/base/arch/export.h"
 #include "pxr/base/arch/stackTrace.h"
 #include "pxr/base/arch/systemInfo.h"
-#if defined(ARCH_OS_LINUX) || defined(ARCH_OS_DARWIN)
+#if defined(ARCH_OS_LINUX) || defined(ARCH_OS_FREEBSD) || defined(ARCH_OS_DARWIN)
 #include "pxr/base/arch/inttypes.h"
 #include <sys/types.h>
 #include <sys/ptrace.h>
@@ -46,6 +46,7 @@
 #include <unistd.h>
 #include <string>
 #endif
+#include <signal.h>
 #if defined(ARCH_OS_DARWIN)
 #include <sys/sysctl.h>
 #endif
@@ -67,7 +68,7 @@ static std::atomic<bool> _archDebuggerWait(false);
 
 static char** _archDebuggerAttachArgs = 0;
 
-#if defined(ARCH_OS_LINUX) || defined(ARCH_OS_DARWIN)
+#if defined(ARCH_OS_LINUX) || defined(ARCH_OS_FREEBSD) || defined(ARCH_OS_DARWIN)
 static
 void
 Arch_DebuggerTrapHandler(int)
@@ -82,7 +83,7 @@ Arch_DebuggerTrapHandler(int)
 }
 #endif
 
-#if defined(ARCH_OS_LINUX) || defined(ARCH_OS_DARWIN)
+#if defined(ARCH_OS_LINUX) || defined(ARCH_OS_FREEBSD) || defined(ARCH_OS_DARWIN)
 static
 void
 Arch_DebuggerInitPosix()
@@ -116,7 +117,7 @@ static
 void
 Arch_DebuggerInit()
 {
-#if defined(ARCH_OS_LINUX) || defined(ARCH_OS_DARWIN)
+#if defined(ARCH_OS_LINUX) || defined(ARCH_OS_FREEBSD) || defined(ARCH_OS_DARWIN)
 #if defined(ARCH_CPU_INTEL) && defined(ARCH_BITS_64)
     // Save some registers that normally don't have to be preserved.  We
     // do this so the caller of ArchDebuggerTrap() can see its arguments
@@ -161,7 +162,7 @@ Arch_DebuggerInit()
 }
 
 
-#if defined(ARCH_OS_LINUX) || defined(ARCH_OS_DARWIN)
+#if defined(ARCH_OS_LINUX) || defined(ARCH_OS_FREEBSD) || defined(ARCH_OS_DARWIN)
 // Use a 'non-locking' fork so that we won't get hung up if we've
 // had malloc corruption.  We can't prevent fork() from using the
 // heap, unfortunately, since fork handlers can do whatever they
@@ -440,7 +441,7 @@ Arch_DebuggerAttach()
         return false;
     }
 
-#if defined(ARCH_OS_LINUX) || defined(ARCH_OS_DARWIN)
+#if defined(ARCH_OS_LINUX) || defined(ARCH_OS_FREEBSD) || defined(ARCH_OS_DARWIN)
 
     // To attach to gdb under Unix/Linux and Gnome:
     //   ARCH_DEBUGGER="gnome-terminal -e 'gdb -p %p'"
@@ -497,7 +498,7 @@ ARCH_HIDDEN
 void
 Arch_InitDebuggerAttach()
 {
-#if defined(ARCH_OS_LINUX) || defined(ARCH_OS_DARWIN)
+#if defined(ARCH_OS_LINUX) || defined(ARCH_OS_FREEBSD) || defined(ARCH_OS_DARWIN)
     // Maximum length of a pid written as a decimal.  It's okay for this
     // to be greater than that.
     static const size_t _decimalPidLength = 20;
