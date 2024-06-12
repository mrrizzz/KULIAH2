#include <stdio.h>
#include <stdlib.h>
#include <limits.h>

#define M INT_MAX
#define N 5

typedef struct 
{
  int content[N];
  int head;
  int tail;
  int count;
} queue;

int Q[N][N] = {
    {M, 1, 3, M, M},
    {M, M, 1, M, 5},
    {3, M, M, 2, M},
    {M, M, M, M, 1},
    {M, M, M, M, M}};

int TQ[N];
int R[N];

void init_queue(queue *q);
void enqueue(queue *q, int value);
int dequeue(queue *q);
int isEmpty(queue q);
int check_queue(queue q, int i);
void print_path(int R[], int node);
void display_matrix(const char *name, int matrix[N][N]);
void djikstra();

int main()
{
  djikstra();
  return 0;
}

void init_queue(queue *q)
{
  q->count = 0;
  q->head = 0;
  q->tail = 0;
}

void enqueue(queue *q, int value)
{
  if (q->count == N)
  {
    printf("Queue overflow\n");
    exit(1);
  }
  q->content[q->tail] = value;
  q->tail = (q->tail + 1) % N;
  q->count++;
}

int dequeue(queue *q)
{
  if (q->count == 0)
  {
    printf("Queue underflow\n");
    exit(1);
  }
  int value = q->content[q->head];
  q->head = (q->head + 1) % N;
  q->count--;
  return value;
}

int isEmpty(queue q)
{
  return q.count == 0;
}

int check_queue(queue q, int i)
{
  int pointer = q.head;
  for (int index = 0; index < q.count; index++)
  {
    if (q.content[pointer] == i)
      return 1;
    pointer = (pointer + 1) % N;
  }
  return 0;
}

void print_path(int R[], int node)
{
  if (node == -1)
    return;
  print_path(R, R[node]);
  printf("%d ", node);
}

void display_matrix(const char *name, int matrix[N][N])
{
  printf("%s:\n", name);
  for (int i = 0; i < N; i++)
  {
    for (int j = 0; j < N; j++)
    {
      if (matrix[i][j] == M)
      {
        printf("M ");
      }
      else
      {
        printf("%d ", matrix[i][j]);
      }
    }
    printf("\n");
  }
}

void djikstra() {
  int node_asal, node_tujuan;
  queue q;

  display_matrix("Matriks Q  ", Q);
  printf("Masukkan node asal (1-5): ");
  scanf("%d", &node_asal);
  printf("Masukkan node tujuan (1-5): ");
  scanf("%d", &node_tujuan);

  node_asal -= 1;   // Adjust to zero-based index
  node_tujuan -= 1; // Adjust to zero-based index

  for (int i = 0; i < N; i++)
  {
    TQ[i] = M;
    R[i] = -1;
  }
  TQ[node_asal] = 0;

  init_queue(&q);
  enqueue(&q, node_asal);

  while (!isEmpty(q))
  {
    int currentNode = dequeue(&q);
    for (int i = 0; i < N; i++)
    {
      if (Q[currentNode][i] != M && TQ[currentNode] != M)
      {
        if (Q[currentNode][i] + TQ[currentNode] < TQ[i])
        {
          TQ[i] = Q[currentNode][i] + TQ[currentNode];
          R[i] = currentNode;
          if (!check_queue(q, i) && i != node_asal && i != node_tujuan)
          {
            enqueue(&q, i);
          }
        }
      }
    }
  }

  printf("Rute terpendek dari %d ke %d adalah: ", node_asal + 1, node_tujuan + 1);
  print_path(R, node_tujuan);
  printf("\n");

  printf("Total beban: %d\n", TQ[node_tujuan]);
  printf("Matriks TQ: ");
  for (int i = 0; i < N; i++)
  {
    printf("%d ", TQ[i]);
  }
  printf("\n");

  printf("Matriks R: ");
  for (int i = 0; i < N; i++)
  {
    printf("%d ", R[i]);
  }
  printf("\n");
}
