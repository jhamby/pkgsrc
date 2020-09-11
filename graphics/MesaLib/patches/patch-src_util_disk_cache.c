$NetBSD $

Hack for Solaris 10's lack of O_CLOEXEC and dirfd().

--- src/util/disk_cache.c.orig	2020-04-29 15:48:25.000000000 +0000
+++ src/util/disk_cache.c	2020-09-02 12:50:25.976049797 +0000
@@ -56,6 +56,14 @@
 
 #include "disk_cache.h"
 
+#if defined(__sun__)
+/* FIXME: hack for Solaris 10. */
+#ifndef O_CLOEXEC
+#define O_CLOEXEC 0
+#endif
+#define dirfd(dirp) ((dirp)->dd_fd)
+#endif
+
 /* Number of bits to mask off from a cache key to get an index. */
 #define CACHE_INDEX_KEY_BITS 16
 
