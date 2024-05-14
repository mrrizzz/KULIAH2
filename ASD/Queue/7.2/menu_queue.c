#include "array.h"

int main(int argc, char const *argv[])
{
  menu_queue();
  return 0;
}

int min;
int max;

void menu_queue()
{
  int choice;
  int value;
  int cont;
  int to_find;

  cont = 1;
  queue q1;
  init_queue(&q1);
  while (cont)
  {
    printf("MENU QUEUE using ARRAY: \n1. Tambah Data\n2. Hapus Data\n3. Menampilkan min & max\n4. Cari Data\n5. Cetak isi Queue\n6. Keluar\n");
    printf("Masukkan pilihan anda : ");
    scanf("%d", &choice);
    getchar();
    switch (choice)
    {
    case 1:
      printf("Masukkan data anda : ");
      scanf(" %d", &value);
      if (!isFull(q1))
        enqueue(&q1, value);
      else
        printf("QUEUE sudah penuh\n");
      break;
    case 2:
      if (!isEmpty(q1))
        dequeue(&q1);
      else
        printf("QUEUE sudah kosong\n");
      break;
    case 3:
      printf("Data terkecil = %d\n", min);
      printf("Data terbesar = %d\n", max);
      break;
    case 4:
      printf("Data yang dicari = ");
      scanf("%d", &to_find);
      printf("%d %s dalam Queue\n", to_find, find(q1, to_find) == 1 ? "ada" : "tidak ada");
      break;
    case 5:
      peek(q1);
      break;
    case 6:
      cont = 0;
      break;
    default:
      break;
    }
    printf("\n");
  }
}

void init_queue(queue *q)
{
  q->count = 0;
  q->head = 0;
  q->tail = 0;
}

int isFull(queue q)
{
  return q.count == QUEUE_LENGTH;
}

int isEmpty(queue q)
{
  return q.count == 0;
}

void enqueue(queue *q, char value)
{
  extern int min;
  extern int max;

  if (q->count == 0)
  {
    min = value;
    max = value;
  }
  else
  {
    if (value > max)
      max = value;
    if (value < min)
      min = value;
  }

  q->content[q->tail] = value;
  q->tail = (q->tail + 1) % QUEUE_LENGTH;
  q->count++;
}

int dequeue(queue *q)
{
  int value;
  value = q->content[q->head];
  q->head = (q->head + 1) % QUEUE_LENGTH;
  q->count--;
  return value;
}

void peek(queue q)
{
  int pointer;
  int index;

  index = 0;
  pointer = q.head;
  printf("isi Queue saat ini adalah\n");
  while (index < q.count)
  {
    printf("%d\n", q.content[pointer]);
    pointer = (pointer + 1) % QUEUE_LENGTH;
    index++;
  }
}

int find(queue q, int to_find)
{
  int pointer;
  int index;

  index = 0;
  pointer = q.head;
  while (index < q.count)
  {
    if (q.content[pointer] == to_find)
      return 1;
    pointer = (pointer + 1) % QUEUE_LENGTH;
    index++;
  }
  return 0;
}