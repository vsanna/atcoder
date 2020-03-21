#!/bin/bash

GCC_OPTIONS='-std=c++17 -Wall -O -g -fsanitize=address'
NAME=`echo $1 | awk -F '.' '{print $1}'`
g++ $GCC_OPTIONS $NAME.cpp -o ./out/$NAME
