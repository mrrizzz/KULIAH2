#include "header.h"

void prepend(){
  allocate();
  if (head != NULL)
  {
    head->prev = newNode;
    newNode->next = head;
  }
  head = newNode;
}

void append(){
  node *tail;

  allocate();
  if (head == NULL)
    head = newNode;
  else
  {
    tail = head;
    while (tail->next != NULL)
      tail = tail->next;

    newNode->prev = tail;
    tail->next = newNode;
    tail = tail->next;
  }
}

void insert(const char *insertMessage)
{
  node *toFindKey;
  int key;

  printf("Insert %s\n", insertMessage);
  if (head == NULL)
  {
    printf("Linked list is empty, not able to insert %s\n", insertMessage);
    return;
  }
  allocate();
  printf("Insert %s ? ", insertMessage);
  scanf("%d", &key);

  toFindKey = head;
  while (toFindKey != NULL && toFindKey->data != key)
    toFindKey = toFindKey->next;

  if (toFindKey == NULL)
  {
    printf("Key is not found\n");
    return;
  }

  if (strcmp(insertMessage, "after") == 0)
  {
    newNode->prev = toFindKey;
    newNode->next = toFindKey->next;
    toFindKey->next->prev = newNode;
    toFindKey->next = newNode;
  }
  else if (strcmp(insertMessage, "before") == 0)
  {
    if (toFindKey == head)
    { 
      toFindKey->prev = newNode;
      newNode->next = toFindKey;
      head = newNode;
    }
    else
    {
      newNode->next = toFindKey->prev->next;
      newNode->prev = toFindKey->prev;
      toFindKey->prev->next = newNode;
      toFindKey->prev = newNode;
    }
  }
}