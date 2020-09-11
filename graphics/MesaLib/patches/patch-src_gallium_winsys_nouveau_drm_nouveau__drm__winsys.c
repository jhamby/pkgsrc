$NetBSD $

Workaround for Solaris 10's lack of F_DUPFD_CLOEXEC.

--- src/gallium/winsys/nouveau/drm/nouveau_drm_winsys.c.orig	2020-04-29 15:48:24.000000000 +0000
+++ src/gallium/winsys/nouveau/drm/nouveau_drm_winsys.c	2020-09-02 20:17:31.302925797 +0000
@@ -17,6 +17,10 @@
 #include <nvif/class.h>
 #include <nvif/cl0080.h>
 
+#ifndef F_DUPFD_CLOEXEC
+#define F_DUPFD_CLOEXEC F_DUPFD
+#endif
+
 static struct util_hash_table *fd_tab = NULL;
 
 static mtx_t nouveau_screen_mutex = _MTX_INITIALIZER_NP;
