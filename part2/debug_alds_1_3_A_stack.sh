#!/bin/sh

SCRIPT=alds_1_3_A_stack.cpp
INPUT1="34 116 + 20 5 - 5 - 1 * +"

# ------------------------

echo "###### COMPILING"
mkdir -p .bin
done=$(clang++ $SCRIPT -o .bin/debug -Werror)
if [ $? -ne 0 ]; then
    echo "-> compile error"
    exit 1
fi
echo "-> done"
echo "###### EXECUTING"

expect -c "
    spawn .bin/debug
    expect \"\"
    send \"$INPUT1\n\"
    interact
"
