$NetBSD$

Change Solaris preprocessor check from "sun" to "__sun".

--- gcc/ada/link.c.orig	2014-08-04 01:00:05.000000000 +0000
+++ gcc/ada/link.c	2020-08-25 19:11:47.450600542 +0000
@@ -183,7 +183,7 @@
 unsigned char __gnat_separate_run_path_options = 0;
 const char *__gnat_default_libgcc_subdir = "lib";
 
-#elif defined (sun)
+#elif defined (__sun)
 const char *__gnat_object_file_option = "";
 const char *__gnat_run_path_option = "-Wl,-R";
 char __gnat_shared_libgnat_default = STATIC;
