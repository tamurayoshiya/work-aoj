#!/bin/sh

echo "###### COMPILING"
mkdir -p .bin
clang++ $1 -o .bin/debug
echo "-> done"
echo "###### EXECUTING"
.bin/debug
