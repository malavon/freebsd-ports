--- gpu/command_buffer/service/shared_image/external_vk_image_backing.cc.orig	2023-03-13 07:33:08 UTC
+++ gpu/command_buffer/service/shared_image/external_vk_image_backing.cc
@@ -34,7 +34,7 @@
 #include "ui/gl/gl_version_info.h"
 #include "ui/gl/scoped_binders.h"
 
-#if (BUILDFLAG(IS_LINUX) || BUILDFLAG(IS_CHROMEOS)) && BUILDFLAG(USE_DAWN)
+#if (BUILDFLAG(IS_LINUX) || BUILDFLAG(IS_CHROMEOS) || BUILDFLAG(IS_BSD)) && BUILDFLAG(USE_DAWN)
 #include "gpu/command_buffer/service/shared_image/external_vk_image_dawn_representation.h"
 #endif
 
@@ -582,7 +582,7 @@ std::unique_ptr<DawnImageRepresentation> ExternalVkIma
     WGPUDevice wgpuDevice,
     WGPUBackendType backend_type,
     std::vector<WGPUTextureFormat> view_formats) {
-#if (BUILDFLAG(IS_LINUX) || BUILDFLAG(IS_CHROMEOS)) && BUILDFLAG(USE_DAWN)
+#if (BUILDFLAG(IS_LINUX) || BUILDFLAG(IS_CHROMEOS) || BUILDFLAG(IS_BSD)) && BUILDFLAG(USE_DAWN)
   auto wgpu_format = ToWGPUFormat(format());
 
   if (wgpu_format == WGPUTextureFormat_Undefined) {
