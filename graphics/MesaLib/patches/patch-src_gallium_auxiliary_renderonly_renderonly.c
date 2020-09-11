$NetBSD $

Workaround for Solaris 10's like of O_CLOEXEC.

--- src/gallium/auxiliary/renderonly/renderonly.c.orig	2020-04-29 15:48:24.000000000 +0000
+++ src/gallium/auxiliary/renderonly/renderonly.c	2020-09-02 20:06:06.415832868 +0000
@@ -101,7 +101,7 @@
    out_handle->type = WINSYS_HANDLE_TYPE_FD;
    out_handle->stride = create_dumb.pitch;
 
-   err = drmPrimeHandleToFD(ro->kms_fd, create_dumb.handle, O_CLOEXEC,
+   err = drmPrimeHandleToFD(ro->kms_fd, create_dumb.handle, DRM_CLOEXEC,
          (int *)&out_handle->handle);
    if (err < 0) {
       fprintf(stderr, "failed to export dumb buffer: %s\n", strerror(errno));
