$NetBSD$

Change Solaris preprocessor check from "sun" to "__sun".

--- boehm-gc/include/private/gcconfig.h.orig	2013-12-21 12:42:39.000000000 +0000
+++ boehm-gc/include/private/gcconfig.h	2020-08-26 08:55:38.541873318 +0000
@@ -74,7 +74,7 @@
 #      define mach_type_known
 #    endif
 # endif
-# if defined(sun) && defined(mc68000)
+# if defined(__sun) && defined(mc68000)
 #    define M68K
 #    define SUNOS4
 #    define mach_type_known
@@ -155,12 +155,12 @@
 #    define SEQUENT
 #    define mach_type_known
 # endif
-# if defined(sun) && (defined(i386) || defined(__i386__))
+# if defined(__sun) && (defined(i386) || defined(__i386__))
 #    define I386
 #    define SUNOS5
 #    define mach_type_known
 # endif
-# if defined(sun) && defined(__amd64)
+# if defined(__sun) && defined(__amd64)
 #    define X86_64
 #    define SUNOS5
 #    define mach_type_known
@@ -174,7 +174,7 @@
 #   define RT
 #   define mach_type_known
 # endif
-# if defined(sun) && (defined(sparc) || defined(__sparc))
+# if defined(__sun) && (defined(sparc) || defined(__sparc))
 #   define SPARC
     /* Test for SunOS 5.x */
 #     include <errno.h>
@@ -185,7 +185,7 @@
 #     endif
 #   define mach_type_known
 # endif
-# if defined(sparc) && defined(unix) && !defined(sun) && !defined(linux) \
+# if defined(sparc) && defined(unix) && !defined(__sun) && !defined(linux) \
      && !defined(__OpenBSD__) && !defined(__NetBSD__) && !defined(__FreeBSD__)
 #   define SPARC
 #   define DRSNX
