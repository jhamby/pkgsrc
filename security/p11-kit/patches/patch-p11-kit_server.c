$NetBSD $

Fix for Solaris 10's lack of SUN_LEN macro.

--- p11-kit/server.c.orig	2020-08-17 23:56:44.000000000 +0000
+++ p11-kit/server.c	2020-09-11 17:05:28.690848443 +0000
@@ -313,7 +313,11 @@
 	}
 
 	umask (066);
+#ifndef SUN_LEN
+	rc = bind (sd, (struct sockaddr *)&sa, sizeof(sa));
+#else
 	rc = bind (sd, (struct sockaddr *)&sa, SUN_LEN (&sa));
+#endif
 	if (rc == -1) {
 		close (sd);
 		p11_message_err (errno, "could not bind socket %s", socket_file);
