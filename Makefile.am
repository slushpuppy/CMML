## Process this with automake to create Makefile.in

AUTOMAKE_OPTIONS = foreign
ACLOCAL_AMFLAGS = -I m4

EXTRA_DIST = include/mml.h include/types.h autogen.sh \
	     include/linux/os.h include/linux/mouse.h \
	     include/windows/os.h include/windows/mouse.h

lib_LTLIBRARIES = libmml.la
libmml_la_SOURCES = src/mouse.c 
libmml_la_CPPFLAGS = -I${srcdir}/include/
libmml_la_LDFLAGS = -version-info 0:0:0

headersdir = ${includedir}/mml
headers_HEADERS = include/mml.h include/types.h include/mouse.h

if LINUX
noinst_LTLIBRARIES = libmml_linux.la
libmml_linux_la_SOURCES = src/linux/os.c src/linux/mouse.c
libmml_la_CPPFLAGS += -I${srcdir}/include/linux/
libmml_linux_la_CPPFLAGS = ${libmml_la_CPPFLAGS}
libmml_linux_la_LIBADD = -lX11
libmml_la_LIBADD = libmml_linux.la
headers_HEADERS += include/linux/os.h
endif

if WINDOWS
noinst_LTLIBRARIES = libmml_win.la
libmml_win_la_SOURCES = src/windows/mouse.c
libmml_la_CPPFLAGS += -I${srcdir}/include/windows/
libmml_win_la_CPPFLAGS =  ${libmml_la_CPPFLAGS}
libmml_la_LIBADD = libmml_win.la
headers_HEADERS += include/windows/os.h
endif

if MAC 
noinst_LTLIBRARIES = libmml_mac.la
libmml_mac_la_SOURCES = src/mac/mouse.c
libmml_mac_la_CPPFLAGS = -I${srcdir}/include/mac/ ${libmml_la_CPPFLAGS}
libmml_la_LIBADD = libmml_mac.la
headers_HEADERS += include/mac/os.h
endif

if LINUX
pkgconfigdir = ${libdir}/pkgconfig
pkgconfig_DATA = mml.pc
endif
