$NetBSD$

Fix for Solaris 10's lack of O_CLOEXEC.

--- amdgpu/amdgpu_device.c.orig	2019-10-16 14:36:48.000000000 +0000
+++ amdgpu/amdgpu_device.c	2020-08-31 19:58:25.653112934 +0000
@@ -177,7 +177,7 @@
 			return r;
 		}
 		if ((flag_auth) && (!flag_authexist)) {
-			dev->flink_fd = fcntl(fd, F_DUPFD_CLOEXEC, 0);
+			dev->flink_fd = fcntl(fd, DRM_CLOEXEC, 0);
 		}
 		*major_version = dev->major_version;
 		*minor_version = dev->minor_version;
@@ -211,7 +211,7 @@
 		goto cleanup;
 	}
 
-	dev->fd = fcntl(fd, F_DUPFD_CLOEXEC, 0);
+	dev->fd = fcntl(fd, DRM_CLOEXEC, 0);
 	dev->flink_fd = dev->fd;
 	dev->major_version = version->version_major;
 	dev->minor_version = version->version_minor;
