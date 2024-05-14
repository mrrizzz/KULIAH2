#include "array.h"

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
  init_queue(&q1);
  while (cont)
  {
    printf("MENU QUEUE using ARRAY: \n1. Mengisi Queue (ENQUEUE)\n2. Mengambil isi Queue (DEQUEUE)\n3. Menampilkan isi queue\n4. Keluar\n");
    printf("Masukkan pilihan anda : ");
    scanf("%d", &choice);
    getchar();
    switch (choice)
    {
    case 1:
      printf("Masukkan data anda : ");
      scanf(" %c", &value);
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
  q->content[q->tail] = value;
  q->tail = (q->tail + 1) % QUEUE_LENGTH;
  q->count++;
}

char dequeue(queue *q)
{
  char value;
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
  while (index < q.count)
  {
    printf("%c\n", q.content[pointer]);
    pointer = (pointer + 1) % QUEUE_LENGTH;
    index++;
  }
}