#include "head.h"

void prepend()
{
  if (head != NULL)
    current->next = head;
  head = current;
}

void insert(node *findKey)
{
  if (findKey != NULL)
    current->next = findKey->next;
  findKey->next = current;
}

void deleteNode()
{
  node *findKey, *prev;
  int key;

  printf("Masukkan Data Yang Ingin Dihapus :  ");
  scanf("%d", &key);

  findKey = head;
  prev = NULL;
  while (findKey != NULL && findKey->data != key)
  {
    prev = findKey;
    findKey = findKey->next;
  }
  if (findKey == NULL)
  {
    printf("Key is not found\n");
  }
  else
  {
    if (findKey == head)
      head = head->next;
    else
      prev->next = findKey->next;
      free(findKey);
      findKey = NULL;
  }
}

void autoInsert()
{
  intOnly == 1 ? allocateOnIntOnly() : allocateOnStruct();
  node *findKey;
  if (head == NULL || current->data <= head->data)
    prepend();
  else
  {
    findKey = head;
    while (findKey->next != NULL && findKey->next->data <= current->data)
      findKey = findKey->next;
    insert(findKey);
  }
}

void findData()
{
  int index;
  int key;
  node *findKey;

  printf("Nomor berapa yang ingin dicari ?  ");
  scanf("%d", &key);

  findKey = head;
  index = 0;
  while (findKey != NULL)
  {
    if (findKey->data == key)
      ++index;
    findKey = findKey->next;
  }
  if (index == 0)
    printf("Key is not found\n");
  else
    printf("Data %d ada %d dalam SLL\n", key, index);
}

void findAverage(){
  float total = 0;
  float average;
  int count = 0; 
  node *findKey = head;
  while (findKey != NULL)
  {
    total += findKey->nilai;
    count++;
    findKey = findKey->next;
  }
  average = total / count;
  printf("\nRata-rata = %.3f", average);
}
