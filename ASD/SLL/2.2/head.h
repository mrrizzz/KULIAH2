#ifndef HEAD_H
#define HEAD_H

#include <stdlib.h>
#include <stdio.h>
#include <string.h>

struct Node
{
    int nomor;
    char nama[50];
    int nilai;
    struct Node *next;
};
typedef struct Node Siswa;

extern Siswa *head; 
extern Siswa *current;

extern int failedInBefore;
extern int failedInAfter;

void clearScreen();
void alokasi();
void tampil();
void free_memory();
void awal();
void akhir();
void after();
void before();
void MenuInsert();

#endif