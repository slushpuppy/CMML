#!/bin/sh
aclocal
autoheader
automake -a
autoreconf --force --install -I config -I m4
