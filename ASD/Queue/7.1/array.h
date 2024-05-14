#ifndef HEADER_H
#define HEADER_H

#include <stdlib.h>
#include <stdio.h>

#define QUEUE_LENGTH 5

typedef struct queue{
  char content[QUEUE_LENGTH];
  int head;
  int tail;
  int count;
}queue;

void menu_queue();
void init_queue(queue *);
char dequeue(queue *);
void enqueue(queue *, char);
void peek(queue);
int isFull(queue);
int isEmpty(queue);

#endif