--- ffsengine.cpp.orig	2020-03-24 04:52:16 UTC
+++ ffsengine.cpp
@@ -11,6 +11,7 @@ WITHWARRANTIES OR REPRESENTATIONS OF ANY KIND, EITHER 
 */
 
 #include <math.h>
+#include <algorithm>
 
 #include "ffsengine.h"
 #include "types.h"
@@ -566,7 +567,7 @@ UINT8 FfsEngine::parseIntelImage(const QByteArray & in
     model->addItem(Types::Region, Subtypes::DescriptorRegion, COMPRESSION_ALGORITHM_NONE, name, "", info, QByteArray(), body, index);
 
     // Sort regions in ascending order
-    qSort(offsets);
+    std::sort(offsets.begin(), offsets.end());
 
     // Parse regions
     UINT8 result = 0;
@@ -2480,13 +2481,13 @@ void FfsEngine::rebasePeiFiles(const QModelIndex & ind
     // Rebase all PE32 and TE sections in PEI-files after modified file
     for (int i = index.row(); i < model->rowCount(index.parent()); i++) {
         // PEI-file
-        QModelIndex currentFileIndex = index.parent().child(i, 0);
+        QModelIndex currentFileIndex = model->index(i, 0, index.parent());
         if (model->subtype(currentFileIndex) == EFI_FV_FILETYPE_PEI_CORE ||
             model->subtype(currentFileIndex) == EFI_FV_FILETYPE_PEIM ||
             model->subtype(currentFileIndex) == EFI_FV_FILETYPE_COMBINED_PEIM_DRIVER) {
             for (int j = 0; j < model->rowCount(currentFileIndex); j++) {
                 // Section in that file
-                QModelIndex currentSectionIndex = currentFileIndex.child(j, 0);
+                QModelIndex currentSectionIndex = model->index(j, 0, currentFileIndex);
                 // If section stores PE32 or TE image
                 if (model->subtype(currentSectionIndex) == EFI_SECTION_PE32 || model->subtype(currentSectionIndex) == EFI_SECTION_TE)
                     // Set rebase action
@@ -2504,13 +2505,13 @@ void FfsEngine::rebasePeiFiles(const QModelIndex & ind
         QModelIndex volumeContainer = parent.parent();
         // Iterate over volumes starting from the one after.
         for (int i = parent.row() + 1; i < model->rowCount(volumeContainer); i++) {
-            QModelIndex currentVolumeIndex = volumeContainer.child(i, 0);
+            QModelIndex currentVolumeIndex = model->index(i, 0, volumeContainer);
             // Iterate over files within each volume after the current one.
             for (int j = 0; j < model->rowCount(currentVolumeIndex); j++) {
-                QModelIndex currentFileIndex = currentVolumeIndex.child(j, 0);
+                QModelIndex currentFileIndex = model->index(j, 0, currentVolumeIndex);
                 if (model->header(currentFileIndex).left(sizeof(EFI_GUID)) == EFI_FFS_VOLUME_TOP_FILE_GUID) {
                     for (int k = 0; k < model->rowCount(currentFileIndex); k++) {
-                        QModelIndex currentSectionIndex = currentFileIndex.child(k, 0);
+                        QModelIndex currentSectionIndex = model->index(k, 0, currentFileIndex);
                         // If section stores PE32 or TE image
                         if (model->subtype(currentSectionIndex) == EFI_SECTION_PE32 || model->subtype(currentSectionIndex) == EFI_SECTION_TE)
                             // Set rebase action
@@ -2703,7 +2704,7 @@ UINT8 FfsEngine::remove(const QModelIndex & index)
     QModelIndex fileIndex;
 
     if (model->type(index) == Types::Volume && model->rowCount(index) > 0)
-        fileIndex = index.child(0, 0);
+        fileIndex = model->index(0, 0, index);
     else if (model->type(index) == Types::File)
         fileIndex = index;
     else if (model->type(index) == Types::Section)
@@ -2728,7 +2729,7 @@ UINT8 FfsEngine::rebuild(const QModelIndex & index)
     QModelIndex fileIndex;
 
     if (model->type(index) == Types::Volume && model->rowCount(index) > 0)
-        fileIndex = index.child(0, 0);
+        fileIndex = model->index(0, 0, index);
     else if (model->type(index) == Types::File)
         fileIndex = index;
     else if (model->type(index) == Types::Section)
@@ -3065,7 +3066,7 @@ UINT8 FfsEngine::reconstructIntelImage(const QModelInd
         reconstructed.clear();
         // First child will always be descriptor for this type of image
         QByteArray descriptor;
-        result = reconstructRegion(index.child(0, 0), descriptor);
+        result = reconstructRegion(model->index(0, 0, index), descriptor);
         if (result)
             return result;
         reconstructed.append(descriptor);
@@ -3150,18 +3151,18 @@ UINT8 FfsEngine::reconstructIntelImage(const QModelInd
             QByteArray region;
 
             // Padding after the end of all Intel regions
-            if (model->type(index.child(i, 0)) == Types::Padding) {
-                region = model->body(index.child(i, 0));
+            if (model->type(model->index(i, 0, index)) == Types::Padding) {
+                region = model->body(model->index(i, 0, index));
                 reconstructed.append(region);
                 offset += region.size();
                 continue;
             }
 
-            result = reconstructRegion(index.child(i, 0), region);
+            result = reconstructRegion(model->index(i, 0, index), region);
             if (result)
                 return result;
 
-            switch (model->subtype(index.child(i, 0)))
+            switch (model->subtype(model->index(i, 0, index)))
             {
             case Subtypes::GbeRegion:
                 gbe = region;
@@ -3257,7 +3258,7 @@ UINT8 FfsEngine::reconstructRegion(const QModelIndex& 
             // Reconstruct children
             for (int i = 0; i < model->rowCount(index); i++) {
                 QByteArray child;
-                result = reconstruct(index.child(i, 0), child);
+                result = reconstruct(model->index(i, 0, index), child);
                 if (result)
                     return result;
                 reconstructed.append(child);
@@ -3385,7 +3386,7 @@ UINT8 FfsEngine::reconstructVolume(const QModelIndex &
 
             // Search for VTF
             for (int i = 0; i < model->rowCount(index); i++) {
-                file = model->header(index.child(i, 0));
+                file = model->header(model->index(i, 0, index));
                 // VTF found
                 if (file.left(sizeof(EFI_GUID)) == EFI_FFS_VOLUME_TOP_FILE_GUID) {
                     baseFound = true;
@@ -3411,17 +3412,17 @@ UINT8 FfsEngine::reconstructVolume(const QModelIndex &
                 // Search for first PEI-file and use it as base source
                 UINT32 fileOffset = header.size();
                 for (int i = 0; i < model->rowCount(index); i++) {
-                    if ((model->subtype(index.child(i, 0)) == EFI_FV_FILETYPE_PEI_CORE ||
-                        model->subtype(index.child(i, 0)) == EFI_FV_FILETYPE_PEIM ||
-                        model->subtype(index.child(i, 0)) == EFI_FV_FILETYPE_COMBINED_PEIM_DRIVER)){
-                        QModelIndex peiFile = index.child(i, 0);
+                    if ((model->subtype(model->index(i, 0, index)) == EFI_FV_FILETYPE_PEI_CORE ||
+                        model->subtype(model->index(i, 0, index)) == EFI_FV_FILETYPE_PEIM ||
+                        model->subtype(model->index(i, 0, index)) == EFI_FV_FILETYPE_COMBINED_PEIM_DRIVER)){
+                        QModelIndex peiFile = model->index(i, 0, index);
                         UINT32 sectionOffset = sizeof(EFI_FFS_FILE_HEADER);
                         // BUGBUG: this parsing is bad and doesn't support large files, but it needs to be performed only for very old images with uncompressed DXE volumes, so whatever
                         // Search for PE32 or TE section
                         for (int j = 0; j < model->rowCount(peiFile); j++) {
-                            if (model->subtype(peiFile.child(j, 0)) == EFI_SECTION_PE32 ||
-                                model->subtype(peiFile.child(j, 0)) == EFI_SECTION_TE) {
-                                QModelIndex image = peiFile.child(j, 0);
+                            if (model->subtype(model->index(j, 0, peiFile)) == EFI_SECTION_PE32 ||
+                                model->subtype(model->index(j, 0, peiFile)) == EFI_SECTION_TE) {
+                                QModelIndex image = model->index(j, 0, peiFile);
                                 // Check for correct action
                                 if (model->action(image) == Actions::Remove || model->action(image) == Actions::Insert)
                                     continue;
@@ -3437,11 +3438,11 @@ UINT8 FfsEngine::reconstructVolume(const QModelIndex &
                                     goto out;
                                 }
                             }
-                            sectionOffset += model->header(peiFile.child(j, 0)).size() + model->body(peiFile.child(j, 0)).size();
+                            sectionOffset += model->header(model->index(j, 0, peiFile)).size() + model->body(model->index(j, 0, peiFile)).size();
                             sectionOffset = ALIGN4(sectionOffset);
                         }
                     }
-                    fileOffset += model->header(index.child(i, 0)).size() + model->body(index.child(i, 0)).size();
+                    fileOffset += model->header(model->index(i, 0, index)).size() + model->body(model->index(i, 0, index)).size();
                     fileOffset = ALIGN8(fileOffset);
                 }
             }
@@ -3459,7 +3460,7 @@ UINT8 FfsEngine::reconstructVolume(const QModelIndex &
             QByteArray nonUefiData;
             for (int i = 0; i < model->rowCount(index); i++) {
                 // Inside a volume can be files, free space or padding with non-UEFI data
-                if (model->type(index.child(i, 0)) == Types::File) { // Next item is a file
+                if (model->type(model->index(i, 0, index)) == Types::File) { // Next item is a file
 
                     // Align to 8 byte boundary
                     UINT32 alignment = offset % 8;
@@ -3473,7 +3474,7 @@ UINT8 FfsEngine::reconstructVolume(const QModelIndex &
                     UINT32 fileBase = volumeBase ? volumeBase + header.size() + offset : 0;
 
                     // Reconstruct file
-                    result = reconstructFile(index.child(i, 0), volumeHeader->Revision, polarity, fileBase, file);
+                    result = reconstructFile(model->index(i, 0, index), volumeHeader->Revision, polarity, fileBase, file);
                     if (result)
                         return result;
 
@@ -3490,11 +3491,11 @@ UINT8 FfsEngine::reconstructVolume(const QModelIndex &
                     if (fileHeader->Type == EFI_FV_FILETYPE_PAD) {
                         padFileGuid = file.left(sizeof(EFI_GUID));
 
-                        if (model->action(index.child(i, 0)) == Actions::DoNotRebuild) {
+                        if (model->action(model->index(i, 0, index)) == Actions::DoNotRebuild) {
                             // User asked not to touch this file, do nothing here
                         }
                         // Parse non-empty pad file
-                        else if (model->rowCount(index.child(i, 0))) {
+                        else if (model->rowCount(model->index(i, 0, index))) {
                             // TODO: handle this special case
                             continue;
                         }
@@ -3507,7 +3508,7 @@ UINT8 FfsEngine::reconstructVolume(const QModelIndex &
                     // Volume Top File
                     if (file.left(sizeof(EFI_GUID)) == EFI_FFS_VOLUME_TOP_FILE_GUID) {
                         vtf = file;
-                        vtfIndex = index.child(i, 0);
+                        vtfIndex = model->index(i, 0, index);
                         continue;
                     }
 
@@ -3540,11 +3541,11 @@ UINT8 FfsEngine::reconstructVolume(const QModelIndex &
                     // Change current file offset
                     offset += file.size();
                 }
-                else if (model->type(index.child(i, 0)) == Types::FreeSpace) { //Next item is a free space
+                else if (model->type(model->index(i, 0, index)) == Types::FreeSpace) { //Next item is a free space
                     // Some data are located beyond free space
-                    if (offset + (UINT32)model->body(index.child(i, 0)).size() < (UINT32)model->body(index).size()) {
+                    if (offset + (UINT32)model->body(model->index(i, 0, index)).size() < (UINT32)model->body(index).size()) {
                         // Get non-UEFI data and it's offset
-                        nonUefiData = model->body(index.child(i + 1, 0));
+                        nonUefiData = model->body(model->index(i + 1, 0, index));
                         nonUefiDataOffset = body.size() - nonUefiData.size();
                         break;
                     }
@@ -3829,7 +3830,7 @@ UINT8 FfsEngine::reconstructFile(const QModelIndex& in
                     
                     // Reconstruct section
                     QByteArray section;
-                    result = reconstructSection(index.child(i, 0), sectionBase, section);
+                    result = reconstructSection(model->index(i, 0, index), sectionBase, section);
                     if (result)
                         return result;
 
@@ -3945,7 +3946,7 @@ UINT8 FfsEngine::reconstructSection(const QModelIndex&
 
                 // Reconstruct subsections
                 QByteArray section;
-                result = reconstruct(index.child(i, 0), section);
+                result = reconstruct(model->index(i, 0, index), section);
                 if (result)
                     return result;
 
@@ -4231,7 +4232,7 @@ UINT8 FfsEngine::findHexPattern(const QModelIndex & in
 
     bool hasChildren = (model->rowCount(index) > 0);
     for (int i = 0; i < model->rowCount(index); i++) {
-        findHexPattern(index.child(i, index.column()), hexPattern, mode);
+        findHexPattern(model->index(i, index.column(), index), hexPattern, mode);
     }
 
     QByteArray data;
@@ -4249,9 +4250,10 @@ UINT8 FfsEngine::findHexPattern(const QModelIndex & in
     }
 
     QString hexBody = QString(data.toHex());
-    QRegExp regexp = QRegExp(QString(hexPattern), Qt::CaseInsensitive);
-    INT32 offset = regexp.indexIn(hexBody);
-    while (offset >= 0) {
+    QRegularExpression regexp(QString(hexPattern), QRegularExpression::CaseInsensitiveOption);
+    QRegularExpressionMatch match = regexp.match(hexBody);
+    while (match.hasMatch()) {
+        INT32 offset = match.capturedStart();
         if (offset % 2 == 0) {
             msg(tr("Hex pattern \"%1\" found as \"%2\" in %3 at %4-offset %5h")
                 .arg(QString(hexPattern))
@@ -4261,7 +4263,7 @@ UINT8 FfsEngine::findHexPattern(const QModelIndex & in
                 .hexarg(offset / 2),
                 index);
         }
-        offset = regexp.indexIn(hexBody, offset + 1);
+        match = regexp.match(hexBody, offset + 1);
     }
 
     return ERR_SUCCESS;
@@ -4277,7 +4279,7 @@ UINT8 FfsEngine::findGuidPattern(const QModelIndex & i
 
     bool hasChildren = (model->rowCount(index) > 0);
     for (int i = 0; i < model->rowCount(index); i++) {
-        findGuidPattern(index.child(i, index.column()), guidPattern, mode);
+        findGuidPattern(model->index(i, index.column(), index), guidPattern, mode);
     }
 
     QByteArray data;
@@ -4318,9 +4320,10 @@ UINT8 FfsEngine::findGuidPattern(const QModelIndex & i
     if (hexPattern.count('.') == hexPattern.length())
         return ERR_SUCCESS;
 
-    QRegExp regexp = QRegExp(QString(hexPattern), Qt::CaseInsensitive);
-    INT32 offset = regexp.indexIn(hexBody);
-    while (offset >= 0) {
+    QRegularExpression regexp(QString(hexPattern), QRegularExpression::CaseInsensitiveOption);
+    QRegularExpressionMatch match = regexp.match(hexBody);
+    while (match.hasMatch()) {
+        INT32 offset = match.capturedStart();
         if (offset % 2 == 0) {
             msg(tr("GUID pattern \"%1\" found as \"%2\" in %3 at %4-offset %5h")
                 .arg(QString(guidPattern))
@@ -4330,7 +4333,7 @@ UINT8 FfsEngine::findGuidPattern(const QModelIndex & i
                 .hexarg(offset / 2),
                 index);
         }
-        offset = regexp.indexIn(hexBody, offset + 1);
+        match = regexp.match(hexBody, offset + 1);
     }
 
     return ERR_SUCCESS;
@@ -4346,7 +4349,7 @@ UINT8 FfsEngine::findTextPattern(const QModelIndex & i
 
     bool hasChildren = (model->rowCount(index) > 0);
     for (int i = 0; i < model->rowCount(index); i++) {
-        findTextPattern(index.child(i, index.column()), pattern, unicode, caseSensitive);
+        findTextPattern(model->index(i, index.column(), index), pattern, unicode, caseSensitive);
     }
 
     if (hasChildren)
@@ -4769,7 +4772,7 @@ UINT8 FfsEngine::recursiveDump(const QModelIndex & ind
 
     UINT8 result;
     for (int i = 0; i < model->rowCount(index); i++) {
-        QModelIndex childIndex = index.child(i, 0);
+        QModelIndex childIndex = model->index(i, 0, index);
         QString childPath = QString("%1/%2 %3").arg(path).arg(i).arg(model->text(childIndex).isEmpty() ? model->name(childIndex) : model->text(childIndex));
         result = recursiveDump(childIndex, childPath, guid);
         if (result)
@@ -4888,15 +4891,16 @@ UINT8 FfsEngine::patchViaPattern(QByteArray & data, co
 
     // Convert file body to hex;
     QString hexBody = QString(body.toHex());
-    QRegExp regexp = QRegExp(QString(hexFindPattern), Qt::CaseInsensitive);
-    INT32 offset = regexp.indexIn(hexBody);
-    while (offset >= 0) {
+    QRegularExpression regexp(QString(hexFindPattern), QRegularExpression::CaseInsensitiveOption);
+    QRegularExpressionMatch match = regexp.match(hexBody);
+    while (match.hasMatch()) {
+        INT32 offset = match.capturedStart();
         if (offset % 2 == 0) {
             UINT8 result = patchViaOffset(body, offset / 2, hexReplacePattern);
             if (result)
                 return result;
         }
-        offset = regexp.indexIn(hexBody, offset + 1);
+        match = regexp.match(hexBody, offset + 1);
     }
 
     data = body;
