## Process this with automake to create Makefile.in

AUTOMAKE_OPTIONS = foreign
ACLOCAL_AMFLAGS = -I m4

EXTRA_DIST = include/mml.h include/types.h autogen.sh \
	     include/linux/os.h include/windows/os.h include/mac/os.h

lib_LTLIBRARIES = libmml.la
libmml_la_SOURCES = src/mml.c src/version.c src/mouse.c \
		    src/keyboard.c src/target.c src/human.c
libmml_la_CPPFLAGS = -I${srcdir}/include/
libmml_la_LDFLAGS = -version-info 0:0:0

headersdir = ${includedir}/mml
headers_HEADERS = include/mml.h include/version.h include/types.h \
		  include/mouse.h include/keyboard.h include/target.h \
		  include/human.h include/color.h

docdir = $(datadir)/doc/mml
doc_DATA = README AUTHORS COPYING

if LINUX
pkgconfigdir = ${libdir}/pkgconfig
pkgconfig_DATA = mml.pc

noinst_LTLIBRARIES = libmml_linux.la
libmml_linux_la_SOURCES = src/linux/os.c src/linux/mouse.c src/linux/keyboard.c
libmml_la_CPPFLAGS += -I${srcdir}/include/linux/
libmml_linux_la_CPPFLAGS = ${libmml_la_CPPFLAGS} -DLINUX
libmml_linux_la_LIBADD = -lX11 -lm
libmml_la_LIBADD = libmml_linux.la
headers_HEADERS += include/linux/os.h
endif

if WINDOWS
noinst_LTLIBRARIES = libmml_win.la
libmml_win_la_SOURCES = src/windows/mouse.c src/windows/keyboard.c
libmml_la_CPPFLAGS += -I${srcdir}/include/windows/
libmml_win_la_CPPFLAGS =  ${libmml_la_CPPFLAGS} -DWINDOWS
libmml_la_LIBADD = libmml_win.la
headers_HEADERS += include/windows/os.h
endif

if MAC 
noinst_LTLIBRARIES = libmml_mac.la
libmml_mac_la_SOURCES = src/mac/mouse.c src/mac/keyboard.c
libmml_la_CPPFLAGS += -I${srcdir}/include/mac/
libmml_mac_la_CPPFLAGS = ${libmml_la_CPPFLAGS} -DMAC -D__NEED_MAC_H_ -ObjC -framework Foundation -framework ApplicationServices
libmml_la_LIBADD = libmml_mac.la
headers_HEADERS += include/mac/os.h
endif
