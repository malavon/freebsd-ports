--- pxr/base/arch/timing.cpp.orig	2022-02-18 21:49:09 UTC
+++ pxr/base/arch/timing.cpp
@@ -38,6 +38,9 @@
 #include <cstdio>
 #include <cstdlib>
 #include <cstring>
+#elif defined(ARCH_OS_FREEBSD)
+#include <sys/types.h>
+#include <sys/sysctl.h>
 #elif defined(ARCH_OS_WINDOWS)
 #include <Windows.h>
 #include <chrono>
@@ -154,6 +157,25 @@ Arch_ComputeNanosecondsPerTick()
     
 #endif
 }
+#elif defined(ARCH_OS_FREEBSD)
+
+ARCH_HIDDEN
+void
+Arch_InitTickTimer()
+{
+#if defined(ARCH_CPU_ARM)
+    uint64_t counter_hz;
+    __asm __volatile("mrs	%0, CNTFRQ_EL0" : "=&r" (counter_hz));
+    Arch_NanosecondsPerTick = double(1e9) / double(counter_hz);
+#else
+    unsigned int freq;
+    size_t len = sizeof(freq);
+    if (sysctlbyname("dev.cpu.1.freq", &freq, &len, NULL, 0))
+        ARCH_ERROR("Cannot retrieve the sysctl value dev.cpu.1.freq");
+    Arch_NanosecondsPerTick = double(1e9) / double(freq*1000000);
+#endif
+}
+
 #elif defined(ARCH_OS_WINDOWS)
 
 static
