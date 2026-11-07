--- treemodel.cpp.orig	2026-11-07 02:02:02 UTC
+++ treemodel.cpp
@@ -52,7 +52,7 @@ Qt::ItemFlags TreeModel::flags(const QModelIndex &inde
 Qt::ItemFlags TreeModel::flags(const QModelIndex &index) const
 {
     if (!index.isValid())
-        return 0;
+        return Qt::ItemFlags{};
 
     return Qt::ItemIsEnabled | Qt::ItemIsSelectable;
 }
@@ -352,4 +352,4 @@ QModelIndex TreeModel::findParentOfType(const QModelIn
         return parent;
 
     return QModelIndex();
-}
\ No newline at end of file
+}
