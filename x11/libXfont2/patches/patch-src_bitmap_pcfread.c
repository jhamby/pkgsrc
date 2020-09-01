$NetBSD$

libnbcompat header file patch for Solaris 10.

--- src/bitmap/pcfread.c.orig	2019-09-14 11:41:35.000000000 +0000
+++ src/bitmap/pcfread.c	2020-08-31 18:46:24.891695637 +0000
@@ -46,7 +46,13 @@
 
 #include <stdarg.h>
 #include <stdint.h>
+#if defined(HAVE_NBCOMPAT_H)
+#include <nbcompat/config.h>    /* needed for the other headers */
+#include <nbcompat/cdefs.h>     /* needed for the other headers */
+#include <nbcompat/string.h>
+#else
 #include <string.h>
+#endif
 
 void
 pcfError(const char* message, ...)
