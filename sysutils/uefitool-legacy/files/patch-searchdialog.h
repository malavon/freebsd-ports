--- searchdialog.h.orig	2026-11-07 01:58:57 UTC
+++ searchdialog.h
@@ -15,7 +15,7 @@
 #define SEARCHDIALOG_H
 
 #include <QDialog>
-#include <QRegExpValidator>
+#include <QRegularExpressionValidator>
 #include "ui_searchdialog.h"
 
 class SearchDialog : public QDialog
@@ -31,8 +31,8 @@ private slots: (private)
     void setEditFocus(int index);
 
 private:
-    QRegExpValidator hexValidator;
-    QRegExpValidator guidValidator;
+    QRegularExpressionValidator hexValidator;
+    QRegularExpressionValidator guidValidator;
 };
 
 #endif
