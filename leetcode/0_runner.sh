#!/bin/bash

NAME=`echo $1 | awk -F '.' '{print $1}'`
./out/$NAME
