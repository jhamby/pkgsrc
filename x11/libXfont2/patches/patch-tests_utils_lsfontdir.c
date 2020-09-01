$NetBSD$

libnbcompat header file patch for Solaris 10.

--- test/utils/lsfontdir.c.orig	2019-09-14 11:41:35.000000000 +0000
+++ test/utils/lsfontdir.c	2020-08-31 18:55:07.738734305 +0000
@@ -30,7 +30,13 @@
 #include "font-test-utils.h"
 #include <stdio.h>
 #include <assert.h>
+#if defined(HAVE_NBCOMPAT_H)
+#include <nbcompat/config.h>    /* needed for the other headers */
+#include <nbcompat/cdefs.h>     /* needed for the other headers */
+#include <nbcompat/err.h>
+#else
 #include <err.h>
+#endif
 
 int
 main(int argc, char **argv)
