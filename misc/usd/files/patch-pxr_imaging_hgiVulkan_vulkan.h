--- pxr/imaging/hgiVulkan/vulkan.h.orig	2022-04-17 18:01:33 UTC
+++ pxr/imaging/hgiVulkan/vulkan.h
@@ -29,7 +29,7 @@
 // Define the platform for Vulkan so vulkan.h below picks the correct includes.
 #if defined(ARCH_OS_WINDOWS)
     #define VK_USE_PLATFORM_WIN32_KHR
-#elif defined(ARCH_OS_LINUX)
+#elif defined(ARCH_OS_LINUX) || defined(ARCH_OS_FREEBSD)
     #define VK_USE_PLATFORM_XLIB_KHR
 #elif defined(ARCH_OS_OSX)
     #define VK_USE_PLATFORM_MACOS_MVK
