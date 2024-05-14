#ifndef POLISH_H
#define POLISH_H

#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#define MAX 10

struct stack
{
  char content[MAX];
  int counter;
};
typedef struct stack stack;

void init(stack *);
void push(char , stack *);
char pop(stack *);
int isFull(stack );
int isEmpty(stack );
void printStack(stack );
void menu();
int convert(char);
void polish();
#endif