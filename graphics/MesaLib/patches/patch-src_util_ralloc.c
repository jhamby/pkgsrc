$NetBSD $

Include strnlen() header for Solaris 10.

--- src/util/ralloc.c.orig	2020-04-29 15:48:25.000000000 +0000
+++ src/util/ralloc.c	2020-09-02 19:15:47.131649830 +0000
@@ -27,6 +27,7 @@
 #include <stdio.h>
 #include <string.h>
 #include <stdint.h>
+#include "strnlen.h"
 
 /* Some versions of MinGW are missing _vscprintf's declaration, although they
  * still provide the symbol in the import library. */
