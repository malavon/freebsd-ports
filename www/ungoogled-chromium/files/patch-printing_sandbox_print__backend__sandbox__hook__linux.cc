--- printing/sandbox/print_backend_sandbox_hook_linux.cc.orig	2023-02-11 09:11:04 UTC
+++ printing/sandbox/print_backend_sandbox_hook_linux.cc
@@ -10,21 +10,28 @@
 #include "base/path_service.h"
 #include "build/build_config.h"
 #include "printing/buildflags/buildflags.h"
+#if !BUILDFLAG(IS_BSD)
 #include "sandbox/linux/syscall_broker/broker_command.h"
 #include "sandbox/linux/syscall_broker/broker_file_permission.h"
 #include "sandbox/policy/export.h"
 #include "sandbox/policy/linux/sandbox_linux.h"
 #include "services/network/network_sandbox_hook_linux.h"
+#else
+#include "sandbox/policy/openbsd/sandbox_openbsd.h"
+#endif
 
 #if BUILDFLAG(IS_CHROMEOS) && BUILDFLAG(USE_CUPS)
 #include "printing/backend/cups_connection_pool.h"
 #endif
 
+#if !BUILDFLAG(IS_BSD)
 using sandbox::syscall_broker::BrokerFilePermission;
 using sandbox::syscall_broker::MakeBrokerCommandSet;
+#endif
 
 namespace printing {
 
+#if !BUILDFLAG(IS_BSD)
 namespace {
 
 sandbox::syscall_broker::BrokerCommandSet GetPrintBackendBrokerCommandSet() {
@@ -85,9 +92,11 @@ std::vector<BrokerFilePermission> GetPrintBackendFileP
 }
 
 }  // namespace
+#endif
 
 bool PrintBackendPreSandboxHook(
     sandbox::policy::SandboxLinux::Options options) {
+#if !BUILDFLAG(IS_BSD)
 #if BUILDFLAG(IS_CHROMEOS) && BUILDFLAG(USE_CUPS)
   // Create the socket connections to the CUPS server before engaging the
   // sandbox, since new connections cannot be made after that.
@@ -101,6 +110,7 @@ bool PrintBackendPreSandboxHook(
       sandbox::policy::SandboxLinux::PreSandboxHook(), options);
 
   instance->EngageNamespaceSandboxIfPossible();
+#endif
   return true;
 }
 
