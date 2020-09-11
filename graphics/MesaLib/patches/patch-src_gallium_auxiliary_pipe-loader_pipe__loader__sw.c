$NetBSD $

Workaround for Solaris 10's lack of F_DUPFD_CLOEXEC.

--- src/gallium/auxiliary/pipe-loader/pipe_loader_sw.c.orig	2020-04-29 15:48:24.000000000 +0000
+++ src/gallium/auxiliary/pipe-loader/pipe_loader_sw.c	2020-09-02 20:11:51.903785622 +0000
@@ -27,6 +27,9 @@
 
 #ifdef HAVE_PIPE_LOADER_KMS
 #include <fcntl.h>
+#ifndef F_DUPFD_CLOEXEC
+#define F_DUPFD_CLOEXEC F_DUPFD
+#endif
 #endif
 
 #include "pipe_loader_priv.h"
