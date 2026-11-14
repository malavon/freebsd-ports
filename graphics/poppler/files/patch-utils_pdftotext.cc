--- utils/pdftotext.cc.orig	2026-11-14 10:38:24 UTC
+++ utils/pdftotext.cc
@@ -434,7 +434,7 @@ static void printInfoString(FILE *f, Dict *infoDict, c
     if (obj.isString()) {
         fputs(text1, f);
         const std::string &s1 = obj.getString();
-        if ((s1.at(0) & 0xff) == 0xfe && (s1.at(1) & 0xff) == 0xff) {
+        if (s1.size() >= 2 && (s1.at(0) & 0xff) == 0xfe && (s1.at(1) & 0xff) == 0xff) {
             isUnicode = true;
             i = 2;
         } else {
