--- searchdialog.cpp.orig	2026-11-07 02:02:54 UTC
+++ searchdialog.cpp
@@ -16,8 +16,8 @@ ui(new Ui::SearchDialog),
 SearchDialog::SearchDialog(QWidget *parent) :
 QDialog(parent),
 ui(new Ui::SearchDialog),
-hexValidator(QRegExp("([0-9a-fA-F\\. ])*")),
-guidValidator(QRegExp("[0-9a-fA-F\\.]{8}-[0-9a-fA-F\\.]{4}-[0-9a-fA-F\\.]{4}-[0-9a-fA-F\\.]{4}-[0-9a-fA-F\\.]{12}"))
+hexValidator(QRegularExpression("([0-9a-fA-F\\. ])*")),
+guidValidator(QRegularExpression("[0-9a-fA-F\\.]{8}-[0-9a-fA-F\\.]{4}-[0-9a-fA-F\\.]{4}-[0-9a-fA-F\\.]{4}-[0-9a-fA-F\\.]{12}"))
 {
     // Create UI
     ui->setupUi(this);
@@ -46,4 +46,4 @@ void SearchDialog::setEditFocus(int index)
     }
     else if (index == 2) // Text
         ui->textEdit->setFocus();
-}
\ No newline at end of file
+}
