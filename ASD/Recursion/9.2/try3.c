#include <stdio.h>
#include <time.h>

int Fibonacci(int);

int main(int argc, char const *argv[])
{
  clock_t start, end;
  double cpu_time_used;
  int n; 

  printf("ingin bilangan fibonacci sampai n ke berapa ? ");
  scanf("%d", &n);

  start = clock();
  for (size_t i = 0; i < n; i++)
  {
    printf("%d  ", Fibonacci(i));
  }
  printf("\n");
  end = clock();

  cpu_time_used = ((double)(end - start)) / CLOCKS_PER_SEC;
  printf("CPU time used: %f seconds\n", cpu_time_used);

  return 0;
}

int Fibonacci(int n)
{
  if (n < 2)
  {
    return n;
  }
  else
  {
    return Fibonacci(n - 1) + Fibonacci(n - 2);
  }
}
