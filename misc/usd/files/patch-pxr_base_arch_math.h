--- pxr/base/arch/math.h.orig	2022-02-18 21:49:09 UTC
+++ pxr/base/arch/math.h
@@ -101,7 +101,7 @@ inline double ArchBitPatternToDouble(uint64_t v) {
 #error Unknown system architecture.
 #endif
 
-#if defined(ARCH_OS_LINUX) || defined(doxygen)
+#if defined(ARCH_OS_LINUX) || defined(ARCH_OS_FREEBSD) || defined(doxygen)
 
 /// Computes the sine and cosine of the specified value as a float.
 inline void ArchSinCosf(float v, float *s, float *c) { sincosf(v, s, c); }
