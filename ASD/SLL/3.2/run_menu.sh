#!/bin/bash

gcc -o tes $(find . -name '*.c' -not -name 'main_single.c') -I.
if [ $? -eq 0 ]; then
    ./tes
fi