#ifndef HEADER_H
#define HEADER_H

#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#define MAX 100

struct stack
{
  int content[MAX];
  int counter;
};
typedef struct stack stack;

void init(stack *);
void push(stack *);
void pop(stack *);
int isFull(stack );
int isEmpty(stack );
void printStack(stack );
void menu();

#endif