--- components/feature_engagement/public/feature_constants.cc.orig	2023-03-13 07:33:08 UTC
+++ components/feature_engagement/public/feature_constants.cc
@@ -19,7 +19,7 @@ BASE_FEATURE(kUseClientConfigIPH,
 BASE_FEATURE(kIPHDummyFeature, "IPH_Dummy", base::FEATURE_DISABLED_BY_DEFAULT);
 
 #if BUILDFLAG(IS_WIN) || BUILDFLAG(IS_APPLE) || BUILDFLAG(IS_LINUX) || \
-    BUILDFLAG(IS_CHROMEOS) || BUILDFLAG(IS_FUCHSIA)
+    BUILDFLAG(IS_CHROMEOS) || BUILDFLAG(IS_FUCHSIA) || BUILDFLAG(IS_BSD)
 BASE_FEATURE(kIPHBatterySaverModeFeature,
              "IPH_BatterySaverMode",
              base::FEATURE_DISABLED_BY_DEFAULT);
@@ -434,7 +434,8 @@ BASE_FEATURE(kIPHiOSDefaultBrowserSettingsBadgeFeature
 #endif  // BUILDFLAG(IS_IOS)
 
 #if BUILDFLAG(IS_WIN) || BUILDFLAG(IS_APPLE) || BUILDFLAG(IS_LINUX) || \
-    BUILDFLAG(IS_CHROMEOS) || BUILDFLAG(IS_ANDROID) || BUILDFLAG(IS_FUCHSIA)
+    BUILDFLAG(IS_CHROMEOS) || BUILDFLAG(IS_ANDROID) || BUILDFLAG(IS_FUCHSIA) || \
+    BUILDFLAG(IS_BSD)
 BASE_FEATURE(kIPHAutofillVirtualCardSuggestionFeature,
              "IPH_AutofillVirtualCardSuggestion",
              base::FEATURE_ENABLED_BY_DEFAULT);
