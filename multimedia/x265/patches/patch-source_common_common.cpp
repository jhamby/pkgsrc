$NetBSD $

Solaris 10: use memalign() instead of posix_memalign().

--- source/common/common.cpp.orig	2020-05-29 10:39:35.000000000 +0000
+++ source/common/common.cpp	2020-09-11 19:57:08.953051620 +0000
@@ -76,12 +76,16 @@
 #else // if _WIN32
 void *x265_malloc(size_t size)
 {
+#ifdef __sun__
+    return memalign(X265_ALIGNBYTES, size);
+#else
     void *ptr;
 
     if (posix_memalign((void**)&ptr, X265_ALIGNBYTES, size) == 0)
         return ptr;
     else
         return NULL;
+#endif
 }
 
 void x265_free(void *ptr)
