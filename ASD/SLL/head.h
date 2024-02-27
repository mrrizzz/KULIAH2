#ifndef HEAD_H
#define HEAD_H

#include <stdlib.h>
#include <stdio.h>

struct simpul
{
    int data;
    struct simpul *next;
};
typedef struct simpul Node;

extern Node *head;
extern Node *current;
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

#endif