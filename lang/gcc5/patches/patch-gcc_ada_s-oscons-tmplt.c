$NetBSD$

Change Solaris preprocessor check from "sun" to "__sun".

--- gcc/ada/s-oscons-tmplt.c.orig	2015-12-04 10:40:14.000000000 +0000
+++ gcc/ada/s-oscons-tmplt.c	2020-08-25 19:12:39.853182575 +0000
@@ -1321,7 +1321,7 @@
  ** hard-wired limit of 100 million.
  ** On IA64 HP-UX the limit is 2**31 - 1.
  **/
-#if defined (sun)
+#if defined (__sun)
 # define MAX_tv_sec "100_000_000"
 
 #elif defined (__hpux__)
