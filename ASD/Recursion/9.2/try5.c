#include <stdio.h>
#include <math.h>

int isPrime(int, int);

int main(int argc, char const *argv[])
{
  int to_check;

  printf("Masukkan angka : ");
  scanf("%d", &to_check);

  printf("%d %s bilangan prima\n", to_check, isPrime(to_check, to_check / 2) == 1 ? "adalah" : "bukan");

  return 0;
}

int isPrime(int x, int divisor)
{
  if (x == 1)
    return 0;
  
  if (divisor >= 2)
  {
    if (x % divisor == 0)
      return 0;
    else
      return isPrime(x, divisor - 1);
  }
  else if (divisor < 2)
    return 1;
}