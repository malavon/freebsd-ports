--- chrome/common/pref_names.cc.orig	2023-03-09 06:31:50 UTC
+++ chrome/common/pref_names.cc
@@ -1222,7 +1222,7 @@ const char kUseAshProxy[] = "lacros.proxy.use_ash_prox
 
 // TODO(crbug.com/1052397): Revisit the macro expression once build flag switch
 // of lacros-chrome is complete.
-#if BUILDFLAG(IS_LINUX) || BUILDFLAG(IS_CHROMEOS_LACROS)
+#if BUILDFLAG(IS_LINUX) || BUILDFLAG(IS_CHROMEOS_LACROS) || BUILDFLAG(IS_BSD)
 // Linux specific preference on whether we should match the system theme.
 const char kUsesSystemThemeDeprecated[] = "extensions.theme.use_system";
 const char kSystemTheme[] = "extensions.theme.system_theme";
@@ -1341,7 +1341,7 @@ const char kShowUpdatePromotionInfoBar[] =
 
 // TODO(crbug.com/1052397): Revisit the macro expression once build flag switch
 // of lacros-chrome is complete.
-#if BUILDFLAG(IS_LINUX) || BUILDFLAG(IS_CHROMEOS_LACROS)
+#if BUILDFLAG(IS_LINUX) || BUILDFLAG(IS_CHROMEOS_LACROS) || BUILDFLAG(IS_BSD)
 // Boolean that is false if we should show window manager decorations.  If
 // true, we draw a custom chrome frame (thicker title bar and blue border).
 const char kUseCustomChromeFrame[] = "browser.custom_chrome_frame";
@@ -1852,7 +1852,7 @@ const char kDownloadDirUpgraded[] = "download.director
 const char kDownloadLastCompleteTime[] = "download.last_complete_time";
 
 #if BUILDFLAG(IS_WIN) || BUILDFLAG(IS_LINUX) || BUILDFLAG(IS_CHROMEOS) || \
-    BUILDFLAG(IS_MAC)
+    BUILDFLAG(IS_MAC) || BUILDFLAG(IS_BSD)
 const char kOpenPdfDownloadInSystemReader[] =
     "download.open_pdf_in_system_reader";
 #endif
@@ -2166,7 +2166,7 @@ const char kWebAppsPreferences[] = "web_apps.web_app_i
 // its isolation requirements.
 const char kWebAppsIsolationState[] = "web_apps.isolation_state";
 
-#if BUILDFLAG(IS_WIN) || BUILDFLAG(IS_MAC) || \
+#if BUILDFLAG(IS_WIN) || BUILDFLAG(IS_MAC) || BUILDFLAG(IS_BSD) || \
     (BUILDFLAG(IS_LINUX) && !BUILDFLAG(IS_CHROMEOS_LACROS))
 // Dictionary that maps origins to web apps that can act as URL handlers.
 const char kWebAppsUrlHandlerInfo[] = "web_apps.url_handler_info";
@@ -2266,7 +2266,7 @@ const char kAmbientAuthenticationInPrivateModesEnabled
 // requests.
 const char kBasicAuthOverHttpEnabled[] = "auth.basic_over_http_enabled";
 
-#if BUILDFLAG(IS_LINUX) || BUILDFLAG(IS_MAC) || BUILDFLAG(IS_CHROMEOS)
+#if BUILDFLAG(IS_LINUX) || BUILDFLAG(IS_MAC) || BUILDFLAG(IS_CHROMEOS) || BUILDFLAG(IS_BSD)
 // Boolean that specifies whether OK-AS-DELEGATE flag from KDC is respected
 // along with kAuthNegotiateDelegateAllowlist.
 const char kAuthNegotiateDelegateByKdcPolicy[] =
@@ -3303,7 +3303,7 @@ const char kBlockAutoplayEnabled[] = "media.block_auto
 const char kSandboxExternalProtocolBlocked[] =
     "profile.sandbox_external_protocol_blocked";
 
-#if BUILDFLAG(IS_LINUX)
+#if BUILDFLAG(IS_LINUX) || BUILDFLAG(IS_BSD)
 // Boolean that indicates if system notifications are allowed to be used in
 // place of Chrome notifications.
 const char kAllowSystemNotifications[] = "system_notifications.allowed";
@@ -3674,7 +3674,7 @@ const char kThrottleNonVisibleCrossOriginIframesAllowe
 const char kNewBaseUrlInheritanceBehaviorAllowed[] =
     "new_base_url_inheritance_behavior_allowed";
 
-#if BUILDFLAG(IS_ANDROID) || BUILDFLAG(IS_LINUX)
+#if BUILDFLAG(IS_ANDROID) || BUILDFLAG(IS_LINUX) || BUILDFLAG(IS_BSD)
 // If this exists and is true, Chrome may run system DNS resolution out of the
 // network process. If false, Chrome will run system DNS resolution in the
 // network process. If non-existent, Chrome will decide where to run system DNS
