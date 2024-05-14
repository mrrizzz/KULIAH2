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
      {
        printf("Data yang dihapus adalah : %c", dequeue(&q1));
      }
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
  newnode->next = NULL;
}

void enqueue(queue *q, char value)
{
  queue *tail;
  alokasi();
  if (head == NULL)
    head = newnode;
  else
  {
    tail = head;
    while (tail->next != NULL)
      tail = tail->next;
    tail->next = newnode;
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

  while (baca != NULL)
  {
    printf("%c\n", baca->data);
    baca = baca->next;
  }
}

void free_node(queue *deleted)
{
  free(deleted);
  deleted = NULL;
}