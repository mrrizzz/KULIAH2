#include <stdio.h>
#include <time.h>
#include <stdlib.h>

int recursiveFibonacci(int);
void iterationFibonacci(int);

int main(int argc, char const *argv[])
{
  clock_t start, end;
  double cpu_time_used;
  int n;
  int choice;

  printf("Menu :\n1. ITERASI\n2. REKURSI\n");
  printf("Masukkan Pilihan : ");
  scanf("%d", &choice);
  printf("ingin bilangan fibonacci sampai n ke berapa ? ");
  scanf("%d", &n);

  start = clock();
  switch (choice)
  {
  case 1:
    iterationFibonacci(n);
    break;

  case 2:
    for (size_t i = 0; i < n; i++)
    {
      printf("%d  ", recursiveFibonacci(i));
    }
    break;

  default:
    break;
  }
  printf("\n");
  end = clock();

  cpu_time_used = ((double)(end - start)) / CLOCKS_PER_SEC;
  printf("CPU time used: %f seconds\n", cpu_time_used);

  return 0;
}

int recursiveFibonacci(int n)
{
  return n < 2 ? n : recursiveFibonacci(n - 1) + recursiveFibonacci(n - 2);
}

void iterationFibonacci(int n)
{
  int *fibonacci;
  fibonacci = (int *)malloc(n * sizeof(fibonacci));
  fibonacci[0] = 0;
  fibonacci[1] = 1;

  for (size_t i = 2; i <= n; i++)
  {
    fibonacci[i] = fibonacci[i - 1] + fibonacci[i - 2];
  }

  for (size_t i = 0; i < n; i++)
  {
    printf("%d  ", fibonacci[i]);
  }
}