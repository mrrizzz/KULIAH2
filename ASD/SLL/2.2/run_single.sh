#!/bin/bash

gcc -o tes *.c single_function/*.c 
if [ $? -eq 0 ]; then
    ./tes
fi