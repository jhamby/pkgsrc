$NetBSD$

Change Solaris preprocessor check from "sun" to "__sun".

--- gcc/ada/gsocket.h.orig	2015-02-20 03:48:57.000000000 +0000
+++ gcc/ada/gsocket.h	2020-08-25 19:11:30.133024309 +0000
@@ -213,7 +213,7 @@
 # define HAVE_THREAD_SAFE_GETxxxBYyyy 1
 
 #elif defined (linux) || defined (__GLIBC__) || \
-     (defined (sun) && defined (__SVR4) && !defined (__vxworks)) || \
+     (defined (__sun) && defined (__SVR4) && !defined (__vxworks)) || \
       defined(__rtems__)
 # define HAVE_GETxxxBYyyy_R 1
 #endif
