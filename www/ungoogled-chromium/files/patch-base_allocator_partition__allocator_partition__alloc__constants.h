--- base/allocator/partition_allocator/partition_alloc_constants.h.orig	2023-03-10 11:01:21 UTC
+++ base/allocator/partition_allocator/partition_alloc_constants.h
@@ -91,7 +91,7 @@ PartitionPageShift() {
   return 18;  // 256 KiB
 }
 #elif (BUILDFLAG(IS_APPLE) && defined(ARCH_CPU_64_BITS)) || \
-    (BUILDFLAG(IS_LINUX) && defined(ARCH_CPU_ARM64))
+    ((BUILDFLAG(IS_LINUX) || BUILDFLAG(IS_BSD)) && defined(ARCH_CPU_ARM64))
 PAGE_ALLOCATOR_CONSTANTS_DECLARE_CONSTEXPR PA_ALWAYS_INLINE size_t
 PartitionPageShift() {
   return PageAllocationGranularityShift() + 2;
@@ -277,7 +277,7 @@ constexpr size_t kNumPools = 3;
 //
 // When pointer compression is enabled, we cannot use large pools (at most
 // 8GB for each of the glued pools).
-#if BUILDFLAG(IS_ANDROID) || BUILDFLAG(IS_IOS) || PA_CONFIG(POINTER_COMPRESSION)
+#if BUILDFLAG(IS_ANDROID) || BUILDFLAG(IS_IOS) || PA_CONFIG(POINTER_COMPRESSION) || BUILDFLAG(IS_BSD)
 constexpr size_t kPoolMaxSize = 8 * kGiB;
 #else
 constexpr size_t kPoolMaxSize = 16 * kGiB;
