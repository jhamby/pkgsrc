$NetBSD$

Change Solaris preprocessor check from "sun" to "__sun".

--- boehm-gc/include/gc.h.orig	2014-10-23 01:39:19.000000000 +0000
+++ boehm-gc/include/gc.h	2020-08-26 08:56:23.531683858 +0000
@@ -1010,7 +1010,7 @@
   * no-op and the collector self-initializes.  But a number of platforms
   * make that too hard.
   */
-#if (defined(sparc) || defined(__sparc)) && defined(sun)
+#if (defined(sparc) || defined(__sparc)) && defined(__sun)
 #   define GC_INIT()
 #else
 # if defined(__CYGWIN32__) || defined (_AIX)
