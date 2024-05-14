#ifndef CONVERT_H
#define CONVERT_H

#include <stdio.h>
#include <stdlib.h>
#include <math.h>
#include <string.h>

#define MAX 100
struct stack
{
  int content[MAX];
  int counter;
};
typedef struct stack stack;

void init(stack *);
void push(int , stack *);
int pop(stack *);
int isFull(stack );
int isEmpty(stack );
void inputNumber();

void convertToBinary(stack number, int input);
void convertToOctal(stack number, int input);
void convertToHexadecimal(stack number, int input);

#endif