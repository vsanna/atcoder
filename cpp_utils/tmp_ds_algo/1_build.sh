#!/bin/bash

GCC_OPTIONS='-std=c++14 -Wall -g'
NAME=`echo $1 | awk -F '.' '{print $1}'`
g++ $GCC_OPTIONS $1 -o ./out/$NAME
