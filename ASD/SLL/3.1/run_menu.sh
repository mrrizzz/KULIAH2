#!/bin/bash

gcc -o tes *.c ./insert_function/*.c $(find ./delete_function -name '*.c' ! -name 'main_single.c')
if [ $? -eq 0 ]; then
    ./tes
fi