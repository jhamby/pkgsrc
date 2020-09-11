$NetBSD: patch-src_util_strndup.h,v 1.2 2019/08/21 13:35:28 nia Exp $

Provide compat strndup for older Darwin and Solaris 10.

--- src/util/strndup.h.orig	2020-04-29 15:48:25.000000000 +0000
+++ src/util/strndup.h	2020-09-02 19:44:09.809982373 +0000
@@ -24,7 +24,9 @@
 #ifndef STRNDUP_H
 #define STRNDUP_H
 
-#if defined(_WIN32)
+#if defined(_WIN32) || (defined(__APPLE__) && __ENVIRONMENT_MAC_OS_X_VERSION_MIN_REQUIRED__-0 < 1070) || defined(__sun__)
+
+#include "util/strnlen.h"
 
 #include <stdlib.h> // size_t
 #include <string.h>
