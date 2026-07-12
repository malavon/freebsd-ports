--- ch341a_spi.c.orig	2025-07-24 01:31:52 UTC
+++ ch341a_spi.c
@@ -72,7 +72,7 @@
 
 
 /* Number of parallel IN transfers. 32 seems to produce the most stable throughput on Windows. */
-#define USB_IN_TRANSFERS 32
+#define USB_IN_TRANSFERS 1
 
 struct ch341a_spi_data {
 	struct libusb_device_handle *handle;
@@ -89,6 +89,7 @@ static const struct dev_entry devs_ch341a_spi[] = {
 
 static const struct dev_entry devs_ch341a_spi[] = {
 	{0x1A86, 0x5512, OK, "Winchiphead (WCH)", "CH341A"},
+	{0x1A86, 0x5523, OK, "Winchiphead (WCH)", "CH341A"},
 
 	{0},
 };
@@ -426,7 +427,7 @@ static int ch341a_spi_init(const struct programmer_cfg
 
 	/* Enable information, warning, and error messages (only). */
 #if LIBUSB_API_VERSION < 0x01000106
-	libusb_set_debug(NULL, 3);
+	libusb_set_debug(NULL, 0);
 #else
 	libusb_set_option(NULL, LIBUSB_OPTION_LOG_LEVEL, LIBUSB_LOG_LEVEL_INFO);
 #endif
