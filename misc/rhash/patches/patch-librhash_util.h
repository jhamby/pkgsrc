$NetBSD$

Solaris 10 doesn't have aligned_alloc().

--- librhash/util.h.orig	2020-07-14 12:35:11.000000000 +0000
+++ librhash/util.h	2020-08-24 17:47:56.245713070 +0000
@@ -39,7 +39,7 @@
 # define rhash_aligned_alloc(alignment, size) _aligned_malloc((size), (alignment))
 # define rhash_aligned_free(ptr) _aligned_free(ptr)
 
-#elif (__STDC_VERSION__ >= 201112L || defined(_ISOC11_SOURCE)) && !defined(__APPLE__)
+#elif (__STDC_VERSION__ >= 201112L || defined(_ISOC11_SOURCE)) && !defined(__APPLE__) && !defined(__sun)
 
 # define HAS_STDC_ALIGNED_ALLOC
 # include <stdlib.h>
