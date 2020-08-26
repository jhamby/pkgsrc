$NetBSD$

Change Solaris preprocessor check from "sun" to "__sun".

--- gcc/ada/init.c.orig	2015-03-04 07:00:57.000000000 +0000
+++ gcc/ada/init.c	2020-08-25 19:11:39.587187133 +0000
@@ -703,7 +703,7 @@
 /* Solaris Section */
 /*******************/
 
-#elif defined (sun) && defined (__SVR4) && !defined (__vxworks)
+#elif defined (__sun) && defined (__SVR4) && !defined (__vxworks)
 
 #include <signal.h>
 #include <siginfo.h>
