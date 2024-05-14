#include "sll.h"

queue *head = NULL, *newnode;

int main(int argc, char const *argv[])
{
  menu_queue();
  return 0;
}

void menu_queue()
{
  int choice;
  char value;
  int cont;
  int priority;

  cont = 1;
  queue q1;
  while (cont)
  {
    printf("MENU QUEUE using ARRAY: \n1. Mengisi Queue (ENQUEUE)\n2. Mengambil isi Queue (DEQUEUE)\n3. Menampilkan isi queue\n4. Keluar\n");
    printf("Masukkan pilihan anda : ");
    scanf("%d", &choice);
    getchar();
    switch (choice)
    {
    case 1:
      enqueue(&q1, value);
      break;
    case 2:
      if (head != NULL)
        printf("Data yang dihapus adalah : %c", dequeue(&q1));
      else
        printf("QUEUE sudah kosong\n");
      break;
    case 3:
      peek(q1);
      break;
    case 4:
      cont = 0;
      break;
    default:
      break;
    }
    printf("\n");
  }
}

void alokasi()
{
  newnode = (queue *)malloc(sizeof(queue));
  if (newnode == NULL)
  {
    printf("gagal mengalokasikan memori\n");
    exit(1);
  }
  printf("Nilai yang akan disimpan : ");
  scanf("%c", &newnode->data);
  getchar();
  printf("Nilai Prioritasnya : ");
  scanf("%d", &newnode->priority);
  newnode->next = NULL;
}

void enqueue(queue *q, char value)
{
  queue *find_position, *prev_find;
  queue *tail;
  alokasi();
  if (head == NULL)
    head = newnode;
  else
  {
    find_position = head;
    prev_find = NULL;
    while (find_position != NULL)
    {
      if (newnode->priority < find_position->priority)
      {
        if (prev_find == NULL)
        {
          newnode->next = head;
          head = newnode;
        }
        else
        {
          newnode->next = prev_find->next;
          prev_find->next = newnode;
        }
        break;
      }
      prev_find = find_position;
      find_position = find_position->next;
    }
    if (find_position == NULL)
      prev_find->next = newnode;
  }
}

char dequeue(queue *q)
{
  queue *temp;
  char value;
  temp = head;
  head = head->next;
  value = temp->data;
  free_node(temp);
  return value;
}

void peek(queue q)
{
  queue *baca;
  baca = head;

  printf("Data\tPrioritas\n");
  while (baca != NULL)
  {
    printf("%c\t%d\n", baca->data, baca->priority);
    baca = baca->next;
  }
}

void free_node(queue *deleted)
{
  free(deleted);
  deleted = NULL;
}