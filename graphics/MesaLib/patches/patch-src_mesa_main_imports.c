$NetBSD $

Use memalign() instead of posix_memalign() on Solaris 10.

--- src/mesa/main/imports.c.orig	2020-04-29 15:48:25.000000000 +0000
+++ src/mesa/main/imports.c	2020-09-02 16:52:33.950841775 +0000
@@ -83,9 +83,13 @@
 {
 #if defined(HAVE_POSIX_MEMALIGN)
    void *mem;
+#if defined(__sun__)
+   mem = memalign(alignment, bytes);
+#else
    int err = posix_memalign(& mem, alignment, bytes);
    if (err)
       return NULL;
+#endif
    return mem;
 #elif defined(_WIN32)
    return _aligned_malloc(bytes, alignment);
