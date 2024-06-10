#include <stdio.h>
#include <limits.h>


#define M INT_MAX
#define V 5


typedef struct
{
 int elements[V];
 int top;
} Stack;


void initializeStack(Stack *s);
int isStackEmpty(Stack *s);
void push(Stack *s, int val);
int pop(Stack *s);


void initializeMatrices(int Q[V][V], int P[V][V], int R[V][V]);
void displayMatrix(const char *name, int matrix[V][V]);
void floydWarshall(int Q[V][V], int P[V][V], int R[V][V]);
void findShortestPath(int R[V][V], int start, int end, int Q[V][V]);


int main()
{
 int Q[V][V], P[V][V], R[V][V];
 int startNode, endNode;


 initializeMatrices(Q, P, R);


 displayMatrix("Matriks Beban (Q)", Q);
 displayMatrix("Matriks Jalur (P)", P);
 displayMatrix("Matriks Rute (R)", R);


 floydWarshall(Q, P, R);


 printf("MATRIKS Q-P-R BARU\n");
 displayMatrix("Matriks Beban Baru (Q)", Q);
 displayMatrix("Matriks Jalur Baru (P)", P);
 displayMatrix("Matriks Rute Baru (R)", R);


 printf("Masukkan Asal (1-5): ");
 scanf("%d", &startNode);
 printf("Masukkan Tujuan (1-5): ");
 scanf("%d", &endNode);


 findShortestPath(R, startNode - 1, endNode - 1, Q);
 printf("Beban = %d\n", Q[startNode - 1][endNode - 1]);


 return 0;
}


void initializeMatrices(int Q[V][V], int P[V][V], int R[V][V])
{
 int i, j;
 int initialCosts[V][V] = {
     {M, 1, 3, M, M},
     {M, M, 1, M, 5},
     {3, M, M, 2, M},
     {M, M, M, M, 1},
     {M, M, M, M, M}};


 for (i = 0; i < V; i++)
 {
   for (j = 0; j < V; j++)
   {
     Q[i][j] = initialCosts[i][j];
     P[i][j] = (i == j || initialCosts[i][j] == M) ? 0 : 1;
     R[i][j] = (i == j || initialCosts[i][j] == M) ? -1 : i;
   }
 }
}


void displayMatrix(const char *name, int matrix[V][V])
{
 printf("%s:\n", name);
 for (int i = 0; i < V; i++)
 {
   for (int j = 0; j < V; j++)
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


void floydWarshall(int Q[V][V], int P[V][V], int R[V][V])
{
 for (int k = 0; k < V; k++)
 {
   for (int i = 0; i < V; i++)
   {
     for (int j = 0; j < V; j++)
     {
       if (Q[i][k] != M && Q[k][j] != M && Q[i][k] + Q[k][j] < Q[i][j])
       {
         Q[i][j] = Q[i][k] + Q[k][j];
         P[i][j] = 1;
         R[i][j] = R[k][j];
       }
     }
   }
 }
}


void initializeStack(Stack *s)
{
 s->top = -1;
}


int isStackEmpty(Stack *s)
{
 return s->top == -1;
}


void push(Stack *s, int val)
{
 if (s->top < V - 1)
 {
   s->elements[++s->top] = val;
 }
}


int pop(Stack *s)
{
 if (!isStackEmpty(s))
 {
   return s->elements[s->top--];
 }
 return -1;
}


void findShortestPath(int R[V][V], int start, int end, int Q[V][V])
{
 Stack s;
 initializeStack(&s);


 printf("Rute terpendek adalah: %d ", start + 1);
 while (R[start][end] != start)
 {
   push(&s, end);
   end = R[start][end];
 }
 printf("-> %d ", end + 1);


 while (!isStackEmpty(&s))
 {
   printf("-> %d ", pop(&s) + 1);
 }
 printf("\n");
}
