#ifndef HEADER_H
#define HEADER_H

#include <stdio.h>
#include <stdlib.h>
#include <string.h>


typedef struct simpul node;
struct simpul 
{
    node *prev;
    int data;
    node *next;
};

extern node *head;
extern node *newNode;

void allocate();
void printList();
void freeNode(node *);
void insertLoopingCheck(void (*insertChoice)(), const char *);
void insertOnlyMenu(const char *);

void deleteMenu();
void insertMenu();
void insertDeleteMenu();

void append();
void prepend();
void insert(const char *);

void deleteHead();
void deleteTail();
void deleteSpecific();

#endif 