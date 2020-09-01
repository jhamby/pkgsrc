$NetBSD$

libnbcompat patch for Solaris 10.

--- amdgpu/amdgpu_asic_id.c.orig	2019-10-16 14:36:48.000000000 +0000
+++ amdgpu/amdgpu_asic_id.c	2020-08-31 19:55:27.614201020 +0000
@@ -29,6 +29,9 @@
 #include <string.h>
 #include <unistd.h>
 #include <errno.h>
+#if defined(HAVE_NBCOMPAT_H)
+extern ssize_t getline(char **, size_t *, FILE *);
+#endif
 
 #include "xf86drm.h"
 #include "amdgpu_drm.h"
