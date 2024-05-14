#include "header.h"

  void deleteHead()
  {
    node *temp;

    temp = head;
    head = head->next;
    freeNode(temp);
  }

void deleteTail()
{
  node *tail;

  tail = head;
  while (tail->next != NULL)
    tail = tail->next;

  if (tail == head)
    deleteHead();
  else
  {
    tail->prev->next = NULL;
    freeNode(tail);
  }
}

void deleteSpecific()
{
  int key;
  node *toFindKey;

  printf("Delete on key... ");
  scanf("%d", &key);
  toFindKey = head;
  while (toFindKey != NULL && toFindKey->data != key)
    toFindKey = toFindKey->next;
  
  if (toFindKey == NULL)
  {
    printf("Key is not found\n");
    return;
  }
  
  if (toFindKey == head)
    deleteHead();
  else
  {
    if (toFindKey->next != NULL)
      toFindKey->next->prev = toFindKey->prev; 
    toFindKey->prev->next = toFindKey->next;
    freeNode(toFindKey);
  }
}