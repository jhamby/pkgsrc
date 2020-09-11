$NetBSD $

Workaround for Solaris 10's lack of F_DUPFD_CLOEXEC.

--- src/gallium/winsys/radeon/drm/radeon_drm_winsys.c.orig	2020-04-29 15:48:24.000000000 +0000
+++ src/gallium/winsys/radeon/drm/radeon_drm_winsys.c	2020-09-02 20:14:40.255737294 +0000
@@ -41,6 +41,10 @@
 #include <fcntl.h>
 #include <radeon_surface.h>
 
+#ifndef F_DUPFD_CLOEXEC
+#define F_DUPFD_CLOEXEC F_DUPFD
+#endif
+
 static struct util_hash_table *fd_tab = NULL;
 static mtx_t fd_tab_mutex = _MTX_INITIALIZER_NP;
 
