#ifndef HEAD_H
#define HEAD_H

#include <stdlib.h>
#include <stdio.h>
#include <string.h>

typedef struct simpul
{
    int data;
    struct simpul *next;
} node;

extern node *head;    
extern node *current;

extern int failed_in_before;
extern int failed_in_after;

void clearScreen();
void alokasi();
void tampil();
void free_memory();
void free_node(node *);

void insert_awal();
void insert_akhir();
void insert_after();
void insert_before();
void insert_looping_check(void (*insert)());
void menu_insert();

void delete_awal();
void delete_akhir();
void delete_specific();
void delete_single_looping_option(void (*delete)(), const char *);
void menu_delete_single();
void menu_delete();

void main_menu();

#endif