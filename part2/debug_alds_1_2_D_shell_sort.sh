#!/bin/sh

SCRIPT=alds_1_2_D_shell_sort.cpp
INPUT1=3
INPUT2=3
INPUT3=2
INPUT4=1
INPUT5=3
INPUT6=2

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
    expect \"\"
    send \"$INPUT2\n\"
    expect \"\"
    send \"$INPUT3\n\"
    expect \"\"
    send \"$INPUT4\n\"
    expect \"\"
    send \"$INPUT5\n\"
    expect \"\"
    send \"$INPUT6\n\"
    interact
"
