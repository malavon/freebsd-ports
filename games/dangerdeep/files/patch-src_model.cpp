--- src/model.cpp.orig	2026-04-04 02:34:43 UTC
+++ src/model.cpp
@@ -571,7 +571,7 @@ void model::mesh::compile()
 	// use uint16 as data type for indices, but it doesn't bring more
 	// performance. OpenGL can do it for use, when we use glDrawRangeElements()
 	// later.
-	index_data.init_data(indices.size() * 4 /* index type is Uint32! */, &indices[0], GL_STATIC_DRAW);
+	index_data.init_data(indices.size() * 4 /* index type is Uint32! */, &indices.data(), GL_STATIC_DRAW);
 }
 
 
