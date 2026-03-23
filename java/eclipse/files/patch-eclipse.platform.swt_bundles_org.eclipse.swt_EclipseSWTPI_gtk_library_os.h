--- eclipse.platform.swt/bundles/org.eclipse.swt/Eclipse SWT PI/gtk/library/os.h.orig	2026-03-26 05:08:22 UTC
+++ eclipse.platform.swt/bundles/org.eclipse.swt/Eclipse SWT PI/gtk/library/os.h	2026-03-26 05:08:22 UTC
@@ -55,10 +55,24 @@
 	                CHECK_DLERROR \
 		}
 
+#if defined(GDK_WINDOWING_WAYLAND)
+#if !GTK_CHECK_VERSION(4,0,0)
+#include <gtk/gtkx.h> // required?
+#include <gdk/gdkwayland.h>
+#else
+#include <gdk/wayland/gdkwayland.h>
+#endif
+#else
+
+#define NO_GDK_1IS_1WAYLAND_1DISPLAY
+// TODO?
+#endif
+
 #if defined(GDK_WINDOWING_X11)
 #if !GTK_CHECK_VERSION(4,0,0)
 #include <gtk/gtkx.h>
 #define NO_gdk_1x11_1surface_1get_1xid
+#include <gdk/gdkx.h>
 #else
 #define NO_gdk_1x11_1get_1default_1xdisplay
 #define NO_gdk_1x11_1window_1get_1xid
@@ -67,13 +81,7 @@
 #define NO_gtk_1plug_1new
 #define NO_gtk_1socket_1get_1id
 #define NO_gtk_1socket_1new
-#endif
-#if !GTK_CHECK_VERSION(4,0,0)
-#include <gdk/gdkx.h>
-#include <gdk/gdkwayland.h>
-#else
 #include <gdk/x11/gdkx.h>
-#include <gdk/wayland/gdkwayland.h>
 #endif
 #else
 
