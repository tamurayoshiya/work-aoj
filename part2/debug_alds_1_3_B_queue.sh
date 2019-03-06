#!/bin/sh

SCRIPT=alds_1_3_B_queue.cpp
INPUT1="5 100"
INPUT2="p1 150"
INPUT3="p2 80"
INPUT4="p3 200"
INPUT5="p4 350"
INPUT6="p5 20"

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
