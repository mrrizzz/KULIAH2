#include <stdio.h>
#include <stdlib.h>
#include <string.h>

struct Node 
{
  int data;
  char nama[30];
  float nilai;
  struct Node *next;
};
typedef struct Node node;

extern node *head;
extern node *current;
extern int intOnly;

void prepend();
void insert(node *);
void autoInsert();
void findData();
void findAverage();
void deleteNode();

void printListOnStruct();
void allocateOnStruct();
void menuOnStruct();

void printListOnIntOnly();
void allocateOnIntOnly();
void menuOnIntOnly();


