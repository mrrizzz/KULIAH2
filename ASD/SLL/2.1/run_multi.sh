#!/bin/bash

gcc -o tes *.c multi_function/*.c single_function/*.c
if [ $? -eq 0 ]; then
    # Jika berhasil, jalankan program
    ./tes
fi