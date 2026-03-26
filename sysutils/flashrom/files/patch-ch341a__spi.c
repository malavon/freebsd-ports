--- ch341a_spi.c.orig	2024-10-24 15:36:39 UTC
+++ ch341a_spi.c
@@ -70,7 +70,7 @@
 
 
 /* Number of parallel IN transfers. 32 seems to produce the most stable throughput on Windows. */
-#define USB_IN_TRANSFERS 32
+#define USB_IN_TRANSFERS 1
 
 /* We need to use many queued IN transfers for any resemblance of performance (especially on Windows)
  * because USB spec says that transfers end on non-full packets and the device sends the 31 reply
@@ -436,7 +436,7 @@ static int ch341a_spi_init(const struct programmer_cfg
 
 	/* Enable information, warning, and error messages (only). */
 #if LIBUSB_API_VERSION < 0x01000106
-	libusb_set_debug(NULL, 3);
+	libusb_set_debug(NULL, 0);
 #else
 	libusb_set_option(NULL, LIBUSB_OPTION_LOG_LEVEL, LIBUSB_LOG_LEVEL_INFO);
 #endif
