$NetBSD$

libnbcompat header file patch for Solaris 10.

--- test/utils/font-test-utils.c.orig	2019-09-14 11:41:35.000000000 +0000
+++ test/utils/font-test-utils.c	2020-08-31 19:02:08.105736238 +0000
@@ -58,7 +58,13 @@
 #include <stdlib.h>
 #include <limits.h>
 #include <assert.h>
+#if defined(HAVE_NBCOMPAT_H)
+#include <nbcompat/config.h>    /* needed for the other headers */
+#include <nbcompat/cdefs.h>     /* needed for the other headers */
+#include <nbcompat/err.h>
+#else
 #include <err.h>
+#endif
 #include <X11/X.h>
 
 static unsigned long server_generation;
@@ -69,12 +75,14 @@
 test_client_auth_generation(ClientPtr client)
 {
     err(BadImplementation, "%s called but not yet implemented", __func__);
+    return 0;
 }
 
 static Bool
 test_client_signal(ClientPtr client)
 {
     err(BadImplementation, "%s called but not yet implemented", __func__);
+    return 0;
 }
 
 static void
@@ -93,6 +101,7 @@
 test_find_old_font(FSID id)
 {
     err(BadImplementation, "%s called but not yet implemented", __func__);
+    return NULL;
 }
 
 static FontResolutionPtr
@@ -112,12 +121,14 @@
 test_get_new_font_client_id(void)
 {
     err(BadImplementation, "%s called but not yet implemented", __func__);
+    return NULL;
 }
 
 static uint32_t
 test_get_time_in_millis(void)
 {
     err(BadImplementation, "%s called but not yet implemented", __func__);
+    return 0;
 }
 
 static int
@@ -125,6 +136,7 @@
 		      FontBlockHandlerProcPtr block_handler)
 {
     err(BadImplementation, "%s called but not yet implemented", __func__);
+    return 0;
 }
 
 /* Callback from libXfont when each fpe handler is registered */
@@ -155,36 +167,42 @@
 test_get_server_client(void)
 {
     err(BadImplementation, "%s called but not yet implemented", __func__);
+    return NULL;
 }
 
 static int
 test_set_font_authorizations(char **authorizations, int *authlen, void *client)
 {
     err(BadImplementation, "%s called but not yet implemented", __func__);
+    return 0;
 }
 
 static int
 test_store_font_client_font(FontPtr pfont, Font id)
 {
     err(BadImplementation, "%s called but not yet implemented", __func__);
+    return 0;
 }
 
 static Atom
 test_make_atom(const char *string, unsigned len, int makeit)
 {
     err(BadImplementation, "%s called but not yet implemented", __func__);
+    return 0;
 }
 
 static int
 test_valid_atom(Atom atom)
 {
     err(BadImplementation, "%s called but not yet implemented", __func__);
+    return 0;
 }
 
 static const char *
 test_name_for_atom(Atom atom)
 {
     err(BadImplementation, "%s called but not yet implemented", __func__);
+    return NULL;
 }
 
 static unsigned long
@@ -197,6 +215,7 @@
 test_add_fs_fd(int fd, FontFdHandlerProcPtr handler, void *data)
 {
     err(BadImplementation, "%s called but not yet implemented", __func__);
+    return 0;
 }
 
 static void
