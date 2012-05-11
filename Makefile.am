## Process this with automake to create Makefile.in

AUTOMAKE_OPTIONS = foreign
ACLOCAL_AMFLAGS = -I m4

EXTRA_DIST = include/mml.h include/types.h autogen.sh \
	     include/linux/os.h include/linux/mouse.h \
	     include/windows/os.h include/windows/mouse.h

lib_LTLIBRARIES = libmml.la
libmml_la_SOURCES = 
libmml_la_CPPFLAGS = -I../include/
libmml_la_LDFLAGS = -version-info 0:0:0

headersdir = ${includedir}/mml
headers_HEADERS = include/mml.h include/types.h include/mouse.h

if LINUX
noinst_LTLIBRARIES = libmml_linux.la
libmml_linux_la_SOURCES = src/linux/os.c src/linux/mouse.c
libmml_linux_la_CPPFLAGS = -I../include/linux/ ${libmml_la_CPPFLAGS}
libmml_linux_la_LIBADD = -lX11
libmml_la_LIBADD = libmml_linux.la
headers_HEADERS += include/linux/os.h
endif

if WINDOWS
noinst_LTLIBRARIES = libmml_win.la
libmml_win_la_SOURCES = src/windows/mouse.c
libmml_win_la_CPPFLAGS = -I../include/windows/ ${libmml_la_CPPFLAGS}
libmml_la_LIBADD = libmml_win.la
headers_HEADERS += include/windows/os.h
endif

if iOS

endif

pkgconfigdir = ${libdir}/pkgconfig
pkgconfig_DATA = mml.pc
