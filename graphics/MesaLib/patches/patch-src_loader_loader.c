$NetBSD $

Include strnlen compat header for Solaris 10.

--- src/loader/loader.c.orig	2020-04-29 15:48:24.000000000 +0000
+++ src/loader/loader.c	2020-09-02 19:43:22.353528085 +0000
@@ -57,6 +57,7 @@
 #endif
 
 #include "util/macros.h"
+#include "util/strndup.h"
 
 #define __IS_LOADER
 #include "pci_id_driver_map.h"
