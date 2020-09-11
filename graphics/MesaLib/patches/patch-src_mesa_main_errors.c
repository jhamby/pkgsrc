$NetBSD $

Include strnlen() header for Solaris 10.

--- src/mesa/main/errors.c.orig	2020-04-29 15:48:25.000000000 +0000
+++ src/mesa/main/errors.c	2020-09-02 19:34:49.194298158 +0000
@@ -35,6 +35,7 @@
 #include "imports.h"
 #include "context.h"
 #include "debug_output.h"
+#include "util/strnlen.h"
 
 
 static FILE *LogFile = NULL;
