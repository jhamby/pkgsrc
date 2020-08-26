$NetBSD$

Change Solaris preprocessor check from "sun" to "__sun".

--- gcc/ada/env.c.orig	2015-02-05 01:09:51.000000000 +0000
+++ gcc/ada/env.c	2020-08-25 19:09:12.406800189 +0000
@@ -211,7 +211,7 @@
   return NULL;
 #elif defined (__MINGW32__)
   return _environ;
-#elif defined (sun)
+#elif defined (__sun)
   extern char **_environ;
   return _environ;
 #elif defined (__APPLE__) && !defined (__arm__)
@@ -229,7 +229,7 @@
 #if defined (VMS)
   /* Not implemented */
   return;
-#elif defined (__hpux__) || defined (sun) \
+#elif defined (__hpux__) || defined (__sun) \
      || (defined (__vxworks) && ! defined (__RTP__)) \
      || defined (_AIX) || defined (__Lynx__)
 
@@ -288,7 +288,7 @@
 #if defined (VMS)
   /* not implemented */
   return;
-#elif defined (sun) \
+#elif defined (__sun) \
   || (defined (__vxworks) && ! defined (__RTP__)) || defined (__Lynx__) \
   || defined (__PikeOS__)
   /* On Solaris, VxWorks (not RTPs), and Lynx there is no system
