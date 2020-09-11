$NetBSD $

Hack for Solaris 10's lack of F_DUPFD_CLOEXEC.

--- src/egl/main/egldisplay.c.orig	2020-04-29 15:48:24.000000000 +0000
+++ src/egl/main/egldisplay.c	2020-09-02 19:50:12.417920777 +0000
@@ -60,6 +60,9 @@
 #include <gbm.h>
 #endif
 
+#ifndef F_DUPFD_CLOEXEC
+#define F_DUPFD_CLOEXEC F_DUPFD
+#endif
 
 /**
  * Map build-system platform names to platform types.
