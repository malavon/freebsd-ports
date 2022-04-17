--- pxr/base/arch/fileSystem.cpp.orig	2022-02-18 21:49:09 UTC
+++ pxr/base/arch/fileSystem.cpp
@@ -51,12 +51,24 @@
 #include <Windows.h>
 #include <WinIoCtl.h>
 #else
+#if !defined(ARCH_OS_FREEBSD)
 #include <alloca.h>
+#else
+#include <stdlib.h>
+#endif
 #include <sys/mman.h>
 #include <sys/file.h>
 #include <unistd.h>
 #endif
 
+#if defined(ARCH_OS_FREEBSD)
+#include <sys/types.h>
+#include <sys/sysctl.h>
+#include <unistd.h>
+#include <stdlib.h>
+#include <sys/user.h>
+#endif
+
 PXR_NAMESPACE_OPEN_SCOPE
 
 using std::pair;
@@ -92,7 +104,7 @@ int ArchRmDir(const char* path)
 bool
 ArchStatIsWritable(const ArchStatType *st)
 {
-#if defined(ARCH_OS_LINUX) || defined (ARCH_OS_DARWIN)
+#if defined(ARCH_OS_LINUX) || defined(ARCH_OS_FREEBSD) || defined (ARCH_OS_DARWIN)
     if (st) {
         return (st->st_mode & S_IWOTH) || 
             ((getegid() == st->st_gid) && (st->st_mode & S_IWGRP)) ||
@@ -129,7 +141,7 @@ ArchGetModificationTime(const char* pathname, double* 
 double
 ArchGetModificationTime(const ArchStatType& st)
 {
-#if defined(ARCH_OS_LINUX)
+#if defined(ARCH_OS_LINUX) || defined(ARCH_OS_FREEBSD)
     return st.st_mtim.tv_sec + 1e-9*st.st_mtim.tv_nsec;
 #elif defined(ARCH_OS_DARWIN)
     return st.st_mtimespec.tv_sec + 1e-9*st.st_mtimespec.tv_nsec;
@@ -386,7 +398,7 @@ ArchGetStatMode(const char *pathname, int *mode)
 double
 ArchGetAccessTime(const struct stat& st)
 {
-#if defined(ARCH_OS_LINUX)
+#if defined(ARCH_OS_LINUX) || defined(ARCH_OS_FREEBSD)
     return st.st_atim.tv_sec + 1e-9*st.st_atim.tv_nsec;
 #elif defined(ARCH_OS_DARWIN)
     return st.st_atimespec.tv_sec + 1e-9*st.st_atimespec.tv_nsec;
@@ -401,7 +413,7 @@ ArchGetAccessTime(const struct stat& st)
 double
 ArchGetStatusChangeTime(const struct stat& st)
 {
-#if defined(ARCH_OS_LINUX)
+#if defined(ARCH_OS_LINUX) || defined(ARCH_OS_FREEBSD)
     return st.st_ctim.tv_sec + 1e-9*st.st_ctim.tv_nsec;
 #elif defined(ARCH_OS_DARWIN)
     return st.st_ctimespec.tv_sec + 1e-9*st.st_ctimespec.tv_nsec;
@@ -431,7 +443,7 @@ ArchGetFileLength(FILE *file)
 {
     if (!file)
         return -1;
-#if defined (ARCH_OS_LINUX) || defined (ARCH_OS_DARWIN)
+#if defined (ARCH_OS_LINUX) || defined (ARCH_OS_FREEBSD) || defined (ARCH_OS_DARWIN)
     struct stat buf;
     return fstat(fileno(file), &buf) < 0 ? -1 :
         static_cast<int64_t>(buf.st_size);
@@ -445,7 +457,7 @@ ArchGetFileLength(FILE *file)
 int64_t
 ArchGetFileLength(const char* fileName)
 {
-#if defined (ARCH_OS_LINUX) || defined (ARCH_OS_DARWIN)
+#if defined (ARCH_OS_LINUX) || defined (ARCH_OS_FREEBSD) || defined (ARCH_OS_DARWIN)
     struct stat buf;
     return stat(fileName, &buf) < 0 ? -1 : static_cast<int64_t>(buf.st_size);
 #elif defined (ARCH_OS_WINDOWS)
@@ -479,6 +491,48 @@ ArchGetFileName(FILE *file)
         result.assign(buf, buf + r);
     }
     return result;
+#elif defined (ARCH_OS_FREEBSD)
+    int mib[4];
+    size_t i, len;
+    char *buffer = NULL;
+    struct kinfo_file *kf;
+    string path;
+
+    mib[0] = CTL_KERN;
+    mib[1] = KERN_PROC;
+    mib[2] = KERN_PROC_FILEDESC;
+    mib[3] = getpid();
+    len = 0;
+    if (sysctl( mib, sizeof(mib)/sizeof(mib[0]), NULL, &len, NULL, 0 ))
+        goto end;
+    len *= 2;
+    buffer = (char*)malloc( len );
+    if (!buffer)
+        goto end;
+    if (sysctl( mib, sizeof(mib)/sizeof(mib[0]), buffer, &len, NULL, 0 ))
+        goto end;
+
+    for (i = 0; i < len; )
+    {
+        kf = (struct kinfo_file*) &buffer[i];
+        if (kf->kf_structsize == 0)
+            break;
+        i += kf->kf_structsize;
+
+        if (kf->kf_fd == fileno(file))
+        {
+            if (kf->kf_path[0])
+            {
+                path.resize(strlen(kf->kf_path) + 1);
+                sprintf(&path[0], "%s", kf->kf_path);
+            }
+            break;
+        }
+    }
+
+end:
+    free( buffer );
+    return path;
 #elif defined (ARCH_OS_DARWIN)
     string result;
     char buf[MAXPATHLEN];
@@ -861,6 +915,9 @@ ArchQueryMappedMemoryResidency(
 {
 #if defined(ARCH_OS_LINUX)
     int ret = mincore(const_cast<void *>(addr), len, pageMap);
+    return ret == 0;
+#elif defined(ARCH_OS_FREEBSD)
+    int ret = mincore(const_cast<const void *>(addr), len, (char *)(pageMap));
     return ret == 0;
 #elif defined (ARCH_OS_DARWIN)
     // On darwin the addr param is 'caddr_t' and the vec param is 'char *'.
