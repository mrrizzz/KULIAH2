#!/bin/bash

gcc -o tes *.c multi_function/*.c $(find ./single_function -name '*.c' ! -name 'main.c')
if [ $? -eq 0 ]; then
    ./tes
fi