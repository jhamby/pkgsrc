$NetBSD$

Change Solaris preprocessor check from "sun" to "__sun".

--- gcc/ada/adaint.c.orig	2015-02-20 03:48:57.000000000 +0000
+++ gcc/ada/adaint.c	2020-08-25 19:04:33.752278788 +0000
@@ -737,7 +737,7 @@
 #endif
 }
 
-#if defined (_WIN32) || defined (linux) || defined (sun) \
+#if defined (_WIN32) || defined (linux) || defined (__sun) \
   || defined (__FreeBSD__)
 #define HAS_TARGET_WCHAR_T
 #endif
@@ -1204,13 +1204,6 @@
 /* Read the next entry in a directory.  The returned string points somewhere
    in the buffer.  */
 
-#if defined (sun) && defined (__SVR4)
-/* For Solaris, be sure to use the 64-bit version, otherwise NFS reads may
-   fail with EOVERFLOW if the server uses 64-bit cookies.  */
-#define dirent dirent64
-#define readdir readdir64
-#endif
-
 char *
 __gnat_readdir (DIR *dirp, char *buffer, int *len)
 {
@@ -2140,8 +2133,8 @@
    return __gnat_is_symbolic_link_attr (name, &attr);
 }
 
-#if defined (sun) && defined (__SVR4)
-/* Using fork on Solaris will duplicate all the threads. fork1, which
+#if defined (__sun) && defined (__SVR4)
+/* Using fork on Solaris 9 and earlier will duplicate all the threads. fork1, which
    duplicates only the active thread, must be used instead, or spawning
    subprocess from a program with tasking will lead into numerous problems.  */
 #define fork fork1
@@ -2247,7 +2240,7 @@
 {
   int cores = 1;
 
-#if defined (linux) || defined (sun) || defined (AIX) || defined (__APPLE__)
+#if defined (linux) || defined (__sun) || defined (AIX) || defined (__APPLE__)
   cores = (int) sysconf (_SC_NPROCESSORS_ONLN);
 
 #elif defined (__hpux__)
