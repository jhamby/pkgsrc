$NetBSD$

Change Solaris preprocessor check from "sun" to "__sun".

--- gcc/ada/terminals.c.orig	2015-03-31 01:30:15.000000000 +0000
+++ gcc/ada/terminals.c	2020-08-25 19:13:18.231434788 +0000
@@ -1083,10 +1083,10 @@
 #include <sys/types.h>
 #include <sys/wait.h>
 #include <unistd.h>
-#if defined (sun)
+#if defined (__sun)
 #   include <sys/stropts.h>
 #endif
-#if defined (FREEBSD) || defined (sun)
+#if defined (FREEBSD) || defined (__sun)
 #   include <sys/signal.h>
 #endif
 #if defined (__hpux__)
@@ -1098,7 +1098,7 @@
 
 /* On HP-UX and Sun system, there is a bzero function but with a different
    signature. Use memset instead */
-#if defined (__hpux__) || defined (sun) || defined (_AIX)
+#if defined (__hpux__) || defined (__sun) || defined (_AIX)
 #   define bzero(s,n) memset (s,0,n)
 #endif
 
@@ -1120,7 +1120,7 @@
 #define USE_OPENPTY
 #elif defined (linux)
 #define USE_GETPT
-#elif defined (sun)
+#elif defined (__sun)
 #define USE_CLONE_DEVICE "/dev/ptmx"
 #elif defined (_AIX)
 #define USE_CLONE_DEVICE "/dev/ptc"
@@ -1406,7 +1406,7 @@
     desc->slave_fd = open (desc->slave_name, O_RDWR, 0);
 #endif
 
-#if defined (sun) || defined (__hpux__)
+#if defined (__sun) || defined (__hpux__)
   /* On systems such as Solaris we are using stream. We need to push the right
      "modules" in order to get the expected terminal behaviors. Otherwise
      functionalities such as termios are not available.  */
