$NetBSD$

libnbcompat patch for Solaris 10.

--- tests/modetest/modetest.c.orig	2019-10-16 14:36:48.000000000 +0000
+++ tests/modetest/modetest.c	2020-09-01 13:19:09.644068966 +0000
@@ -54,6 +54,9 @@
 #ifdef HAVE_SYS_SELECT_H
 #include <sys/select.h>
 #endif
+#if defined(HAVE_NBCOMPAT_H)
+extern char *strndup(const char *s1, size_t n);
+#endif
 
 #include "xf86drm.h"
 #include "xf86drmMode.h"
