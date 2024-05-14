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

struct simpul
{
    int data;
    struct simpul *next;
};
typedef struct simpul Node;

extern Node *head; // comment out this line when not using the multi function
extern Node *current;// comment out this line when not using the multi function

extern int failedInBefore;
extern int failedInAfter;

void autoInsert();
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