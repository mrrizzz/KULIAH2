#include<stdio.h>
#include<stdlib.h>

void printFibonacci(int );

int main(int argc, char const *argv[])
{
  int n;

  printf("ingin bilangan fibonacci sampai n ke berapa ? ");
  scanf("%d", &n);

  printFibonacci(n);
  return 0;
}

void printFibonacci(int n){
  int *fibonacci;
  fibonacci = (int *)malloc(n * sizeof(fibonacci));
  fibonacci[0] = 0;
  fibonacci[1] = 1;

  
  for (size_t i = 2; i <= n; i++)
  {
    fibonacci[i] = fibonacci[i-1] + fibonacci[i-2];
  }

  for (size_t i = 0; i < n; i++)
  {
    printf("%d  ", fibonacci[i]);
  }

}