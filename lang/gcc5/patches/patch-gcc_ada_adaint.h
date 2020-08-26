$NetBSD$

Change Solaris preprocessor check from "sun" to "__sun".

--- gcc/ada/adaint.h.orig	2015-01-27 09:20:27.000000000 +0000
+++ gcc/ada/adaint.h	2020-08-25 19:06:53.263858823 +0000
@@ -51,7 +51,7 @@
    determine at compile time what support the system offers for large files.
    For now we just list the platforms we have manually tested. */
 
-#if defined (__GLIBC__) || defined (sun)
+#if defined (__GLIBC__)
 #define GNAT_FOPEN fopen64
 #define GNAT_OPEN open64
 #define GNAT_STAT stat64
