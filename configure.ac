#                                               -*- Autoconf -*-
# Process this file with autoconf to produce a configure script.

AC_PREREQ([2.68])
AC_INIT([MML],[0.0.0],[Dgby714@gmail.com],[mml],[https://github.com/Dgby714/CMML])

AC_CONFIG_AUX_DIR([config])

AM_INIT_AUTOMAKE([foreign silent-rules])
AM_SILENT_RULES([yes])
AM_MAINTAINER_MODE

AC_CONFIG_MACRO_DIR([m4])
AC_CONFIG_SRCDIR([src/linux/os.c])
AC_CONFIG_HEADERS([config.h])

PKG_PROG_PKG_CONFIG
LT_INIT([dlopen])
AC_PROG_CC
AC_PROG_CXX

AC_MSG_CHECKING([platform])
TARGET=unknown
case "$host" in
  *-linux-*)
    TARGET=LINUX;  
    ;;
  *-win32* | *-cygwin* | *-mingw*)
    TARGET=WINDOWS
    ;;
  *-darwin*)
    TARGET=MAC
    ;;
esac

AC_MSG_RESULT([$TARGET])

if test "$TARGET" = unknown; then
  if test x"$host" = x; then
    AC_MSG_ERROR([mml has not been ported to your platform.])
  fi
  
  AC_MSG_ERROR([mml has not been ported to "$host".])
fi

AM_CONDITIONAL(LINUX, test x"$TARGET" = xLINUX)
AM_CONDITIONAL(WINDOWS, test x"$TARGET" = xWINDOWS)
AM_CONDITIONAL(MAC, test x"$TARGET" = xMAC)

AC_PATH_X
AC_CHECK_HEADERS([stdlib.h])

AC_CHECK_FUNCS([memset])
AC_HEADER_STDBOOL
AC_C_INLINE

AC_TYPE_UINT32_T
AC_TYPE_UINT8_T

AC_CONFIG_FILES([Makefile mml.pc])
AC_OUTPUT
