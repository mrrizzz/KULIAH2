#ifndef HEADER_H
#define HEADER_H

#include <stdlib.h>
#include <stdio.h>

#define QUEUE_LENGTH 10

typedef struct queue
{
  char data;
  struct queue *next;
} queue;

void menu_queue();
char dequeue(queue *);
void enqueue(queue *, char);
void peek(queue);
int isEmpty(queue);

void free_node(queue *);

#endif