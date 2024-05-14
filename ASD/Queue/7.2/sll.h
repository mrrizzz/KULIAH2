#ifndef HEADER_H
#define HEADER_H

#include <stdlib.h>
#include <stdio.h>

typedef struct queue
{
  char data;
  int priority;
  struct queue *next;
} queue;

void menu_queue();
char dequeue(queue *);
void enqueue(queue *, char);
void peek(queue);
int isEmpty(queue);

void free_node(queue *);

#endif