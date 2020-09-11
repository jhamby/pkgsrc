$NetBSD $

Patch for Solaris 10 to use memalign() instead of posix_memalign().

--- src/util/os_memory_stdc.h.orig	2020-04-29 15:48:25.000000000 +0000
+++ src/util/os_memory_stdc.h	2020-09-02 12:35:20.247894744 +0000
@@ -53,8 +53,12 @@
 {
    void *ptr;
    alignment = (alignment + sizeof(void*) - 1) & ~(sizeof(void*) - 1);
+#if defined(__sun__)
+   ptr = memalign(alignment, size);
+#else
    if(posix_memalign(&ptr, alignment, size) != 0)
       return NULL;
+#endif
    return ptr;
 }
 
