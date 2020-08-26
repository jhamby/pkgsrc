$NetBSD$

Change Solaris preprocessor check from "sun" to "__sun".

--- gcc/ada/tracebak.c.orig	2014-10-20 07:11:43.000000000 +0000
+++ gcc/ada/tracebak.c	2020-08-25 19:13:46.142589511 +0000
@@ -363,7 +363,7 @@
 
 /*-------------------------- SPARC Solaris -----------------------------*/
 
-#elif defined (sun) && defined (sparc)
+#elif defined (__sun) && defined (__sparc)
 
 #define USE_GENERIC_UNWINDER
 
@@ -406,7 +406,7 @@
 #if defined (__WIN32)
 #include <windows.h>
 #define IS_BAD_PTR(ptr) (IsBadCodePtr((FARPROC)ptr))
-#elif defined (sun)
+#elif defined (__sun)
 #define IS_BAD_PTR(ptr) ((unsigned long)ptr == -1UL)
 #else
 #define IS_BAD_PTR(ptr) 0
