#!/bin/sh

test_a=`./rush1-1 0 0 | ./rush3 > test1 && ./rush1-1 0 0 | ./../rush3 > test2 && diff test1 test2 | echo $?`

if [ -z $test_a ]; then
    echo "[TEST1 RUSH1-1] SUCCESSFUL TEST!"
else
    echo "[TEST1 RUSH1-1] TEST FAILURE... :("
fi

test_b=`./rush1-1 0 1 | ./rush3 > test1 && ./rush1-1 0 1 | ./../rush3 > test2 && diff test1 test2 | echo $?`

if [ -z $test_b ]; then
    echo "[TEST2 RUSH1-1] SUCCESSFUL TEST!"
else
    echo "[TEST2 RUSH1-1] TEST FAILURE... :("
fi

test_c=`./rush1-1 3 3 | ./rush3 > test1 && ./rush1-1 3 3 | ./../rush3 > test2 && diff test1 test2 | echo $?`

if [ -z $test_c ]; then
    echo "[TEST3 RUSH1-1] SUCCESSFUL TEST!"
else
    echo "[TEST3 RUSH1-1] TEST FAILURE... :("
fi

test_d=`./rush1-2 0 0 | ./rush3 > test1 && ./rush1-2 0 0 | ./../rush3 > test2 && diff test1 test2 | echo $?`

if [ -z $test_b ]; then
    echo "[TEST1] SUCCESSFUL TEST!"
else
    echo "[TEST1] TEST FAILURE... :("
fi

test_e=`./rush1-2 0 1 | ./rush3 > test1 && ./rush1-2 0 1 | ./../rush3 > test2 && diff test1 test2 | echo $?`

if [ -z $test_b ]; then
    echo "[TEST1] SUCCESSFUL TEST!"
else
    echo "[TEST1] TEST FAILURE... :("
fi

test_f=`./rush1-2 5 5 | ./rush3 > test1 && ./rush1-2 5 5 | ./../rush3 > test2 && diff test1 test2 | echo $?`

if [ -z $test_b ]; then
    echo "[TEST1] SUCCESSFUL TEST!"
else
    echo "[TEST1] TEST FAILURE... :("
fi

test_g=`./rush1-3 0 0 | ./rush3 > test1 && ./rush1-3 0 0 | ./../rush3 > test2 && diff test1 test2 | echo $?`

if [ -z $test_b ]; then
    echo "[TEST1] SUCCESSFUL TEST!"
else
    echo "[TEST1] TEST FAILURE... :("
fi

test_h=`./rush1-3 0 1 | ./rush3 > test1 && ./rush1-3 0 1 | ./../rush3 > test2 && diff test1 test2 | echo $?`

if [ -z $test_b ]; then
    echo "[TEST1] SUCCESSFUL TEST!"
else
    echo "[TEST1] TEST FAILURE... :("
fi

test_i=`./rush1-3 5 5 | ./rush3 > test1 && ./rush1-3 5 5 | ./../rush3 > test2 && diff test1 test2 | echo $?`

if [ -z $test_b ]; then
    echo "[TEST1] SUCCESSFUL TEST!"
else
    echo "[TEST1] TEST FAILURE... :("
fi

test_j=`./rush1-3 1 1 | ./rush3 > test1 && ./rush1-3 1 1 | ./../rush3 > test2 && diff test1 test2 | echo $?`

if [ -z $test_b ]; then
    echo "[TEST1] SUCCESSFUL TEST!"
else
    echo "[TEST1] TEST FAILURE... :("
fi

test_k=`./rush1-4 1 1 | ./rush3 > test4 && ./rush1-4 1 1 | ./../rush3 > test2 && diff test1 test2 | echo $?`

if [ -z $test_b ]; then
    echo "[TEST1] SUCCESSFUL TEST!"
else
    echo "[TEST1] TEST FAILURE... :("
fi

test_l=`./rush1-4 5 5 | ./rush3 > test1 && ./rush1-4 5 5 | ./../rush3 > test2 && diff test1 test2 | echo $?`

if [ -z $test_b ]; then
    echo "[TEST1] SUCCESSFUL TEST!"
else
    echo "[TEST1] TEST FAILURE... :("
fi

test_m=`./rush1-5 1 1 | ./rush3 > test1 && ./rush1-5 1 1 | ./../rush3 > test2 && diff test1 test2 | echo $?`

if [ -z $test_b ]; then
    echo "[TEST1] SUCCESSFUL TEST!"
else
    echo "[TEST1] TEST FAILURE... :("
fi

test_n=`./rush1-5 5 5 | ./rush3 > test1 && ./rush1-5 5 5 | ./../rush3 > test2 && diff test1 test2 | echo $?`

if [ -z $test_b ]; then
    echo "[TEST1] SUCCESSFUL TEST!"
else
    echo "[TEST1] TEST FAILURE... :("
fi
