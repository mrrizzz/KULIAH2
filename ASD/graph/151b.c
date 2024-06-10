#include <stdio.h>
#include <stdlib.h>
#include <limits.h>

#define M INT_MAX

typedef struct {
    int *elements;
    int top;
    int capacity;
} Stack;

void initializeStack(Stack *s, int capacity);
int isStackEmpty(Stack *s);
void push(Stack *s, int val);
int pop(Stack *s);

void initializeMatrices(int **Q, int **P, int **R, int V);
void displayMatrix(const char *name, int **matrix, int V);
void floydWarshall(int **Q, int **P, int **R, int V);
void findShortestPath(int **R, int start, int end, int **Q, int V);

int main() {
    int V;
    int **Q, **P, **R;
    int startNode, endNode;

    printf("Masukkan jumlah node: ");
    scanf("%d", &V);

    Q = (int **)malloc(V * sizeof(int *));
    P = (int **)malloc(V * sizeof(int *));
    R = (int **)malloc(V * sizeof(int *));
    for (int i = 0; i < V; i++) {
        Q[i] = (int *)malloc(V * sizeof(int));
        P[i] = (int *)malloc(V * sizeof(int));
        R[i] = (int *)malloc(V * sizeof(int));
    }

    initializeMatrices(Q, P, R, V);

    displayMatrix("Matriks Beban (Q)", Q, V);
    displayMatrix("Matriks Jalur (P)", P, V);
    displayMatrix("Matriks Rute (R)", R, V);

    floydWarshall(Q, P, R, V);

    printf("MATRIKS Q-P-R BARU\n");
    displayMatrix("Matriks Beban Baru (Q)", Q, V);
    displayMatrix("Matriks Jalur Baru (P)", P, V);
    displayMatrix("Matriks Rute Baru (R)", R, V);

    printf("Masukkan Asal (1-%d): ", V);
    scanf("%d", &startNode);
    printf("Masukkan Tujuan (1-%d): ", V);
    scanf("%d", &endNode);

    findShortestPath(R, startNode - 1, endNode - 1, Q, V);
    printf("Beban = %d\n", Q[startNode - 1][endNode - 1]);

    for (int i = 0; i < V; i++) {
        free(Q[i]);
        free(P[i]);
        free(R[i]);
    }
    free(Q);
    free(P);
    free(R);

    return 0;
}

void initializeMatrices(int **Q, int **P, int **R, int V) {
    printf("Masukkan matriks beban (gunakan %d untuk melambangkan tak hingga):\n", M);
    for (int i = 0; i < V; i++) {
        for (int j = 0; j < V; j++) {
            scanf("%d", &Q[i][j]);
            P[i][j] = (i == j || Q[i][j] == M) ? 0 : 1;
            R[i][j] = (i == j || Q[i][j] == M) ? -1 : i;
        }
    }
}

void displayMatrix(const char *name, int **matrix, int V) {
    printf("%s:\n", name);
    for (int i = 0; i < V; i++) {
        for (int j = 0; j < V; j++) {
            if (matrix[i][j] == M) {
                printf("M ");
            } else {
                printf("%d ", matrix[i][j]);
            }
        }
        printf("\n");
    }
}

void floydWarshall(int **Q, int **P, int **R, int V) {
    for (int k = 0; k < V; k++) {
        for (int i = 0; i < V; i++) {
            for (int j = 0; j < V; j++) {
                if (Q[i][k] != M && Q[k][j] != M && Q[i][k] + Q[k][j] < Q[i][j]) {
                    Q[i][j] = Q[i][k] + Q[k][j];
                    P[i][j] = 1;
                    R[i][j] = R[k][j];
                }
            }
        }
    }
}

void initializeStack(Stack *s, int capacity) {
    s->top = -1;
    s->capacity = capacity;
    s->elements = (int *)malloc(capacity * sizeof(int));
}

int isStackEmpty(Stack *s) {
    return s->top == -1;
}

void push(Stack *s, int val) {
    if (s->top < s->capacity - 1) {
        s->elements[++s->top] = val;
    }
}

int pop(Stack *s) {
    if (!isStackEmpty(s)) {
        return s->elements[s->top--];
    }
    return -1;
}

void findShortestPath(int **R, int start, int end, int **Q, int V) {
    Stack s;
    initializeStack(&s, V);

    printf("Rute terpendek adalah: %d ", start + 1);
    while (R[start][end] != start) {
        push(&s, end);
        end = R[start][end];
    }
    printf("-> %d ", end + 1);

    while (!isStackEmpty(&s)) {
        printf("-> %d ", pop(&s) + 1);
    }
    printf("\n");

    free(s.elements);
}
