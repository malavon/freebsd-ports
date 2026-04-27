--- src/unix/glegl.cpp.orig	2026-04-27 02:51:00 UTC
+++ src/unix/glegl.cpp
@@ -689,6 +689,7 @@ wxGLCanvasEGL::~wxGLCanvasEGL()
     // disconnect it to avoid accessing this object when it's already destroyed
     // by wxGLCanvas dtor (and it is useless anyhow now as all it does is to
     // call DestroyWaylandSubsurface() which we already do just below).
+#ifdef GDK_WINDOWING_WAYLAND
     if ( m_canvas && m_canvas->m_widget )
     {
         g_signal_handlers_disconnect_by_func(
@@ -697,6 +698,7 @@ wxGLCanvasEGL::~wxGLCanvasEGL()
             this
         );
     }
+#endif
 
     if ( m_surface )
         eglDestroySurface(m_display, m_surface);
