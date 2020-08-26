$NetBSD$

Change Solaris preprocessor check from "sun" to "__sun".

--- gcc/ada/cstreams.c.orig	2014-08-04 06:09:07.000000000 +0000
+++ gcc/ada/cstreams.c	2020-08-25 19:11:17.567004737 +0000
@@ -277,7 +277,7 @@
   return _fseeki64 (stream, offset, origin);
 }
 
-#elif defined(linux) || defined(sun) \
+#elif defined(linux) || defined(__sun) \
   || defined (__FreeBSD__) || defined(__APPLE__)
 /* section for platforms having ftello/fseeko */
 
