#!/bin/sh
mkdir -p m4
mkdir -p config
autoreconf --install --force -Im4 -Iconfig
