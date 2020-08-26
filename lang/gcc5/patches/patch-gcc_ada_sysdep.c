$NetBSD$

Change Solaris preprocessor check from "sun" to "__sun".

--- gcc/ada/sysdep.c.orig	2015-02-20 03:48:57.000000000 +0000
+++ gcc/ada/sysdep.c	2020-08-25 19:12:57.814329975 +0000
@@ -66,7 +66,7 @@
 #include <time.h>
 #include <errno.h>
 
-#if defined (sun) && defined (__SVR4) && !defined (__vxworks)
+#if defined (__sun) && defined (__SVR4) && !defined (__vxworks)
 /* The declaration is present in <time.h> but conditionalized
    on a couple of macros we don't define.  */
 extern struct tm *localtime_r(const time_t *, struct tm *);
@@ -282,7 +282,7 @@
 }
 #endif
 
-#if defined (linux) || defined (sun) \
+#if defined (linux) || defined (__sun) \
   || defined (WINNT) \
   || defined (__MACHTEN__) || defined (__hpux__) || defined (_AIX) \
   || (defined (__svr4__) && defined (i386)) || defined (__Lynx__) \
@@ -335,7 +335,7 @@
                        int *avail,
                        int waiting ATTRIBUTE_UNUSED)
 {
-#if defined (linux) || defined (sun) \
+#if defined (linux) || defined (__sun) \
     || defined (__CYGWIN32__) || defined (__MACHTEN__) || defined (__hpux__) \
     || defined (_AIX) || (defined (__svr4__) && defined (i386)) \
     || defined (__Lynx__) || defined (__FreeBSD__) || defined (__OpenBSD__) \
@@ -355,7 +355,7 @@
       /* Set RAW mode, with no echo */
       termios_rec.c_lflag = termios_rec.c_lflag & ~ICANON & ~ECHO;
 
-#if defined(linux) || defined (sun) \
+#if defined(linux) || defined (__sun) \
     || defined (__MACHTEN__) || defined (__hpux__) \
     || defined (_AIX) || (defined (__svr4__) && defined (i386)) \
     || defined (__Lynx__) || defined (__FreeBSD__) || defined (__OpenBSD__) \
@@ -756,7 +756,7 @@
   struct tm tp ATTRIBUTE_UNUSED;
 
 /* AIX, HPUX, Sun Solaris */
-#if defined (_AIX) || defined (__hpux__) || defined (sun)
+#if defined (_AIX) || defined (__hpux__) || defined (__sun)
 {
   (*Lock_Task) ();
 
