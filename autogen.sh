#!/bin/sh
aclocal -Im4
libtoolize --copy --force
autoheader
automake --add-missing --copy --foreign
autoconf
