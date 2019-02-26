#!/bin/sh

SCRIPT=alds_1_2_C_stable_sort.cpp
INPUT1=5
INPUT2="H4 C9 S4 D2 C3"

# ------------------------

echo "###### COMPILING"
mkdir -p .bin
clang++ $SCRIPT -o .bin/debug
echo "-> done"
echo "###### EXECUTING"

expect -c "
    spawn .bin/debug
    expect \"\"
    send \"$INPUT1\n\"
    expect \"\"
    send \"$INPUT2\n\"
    interact
"
