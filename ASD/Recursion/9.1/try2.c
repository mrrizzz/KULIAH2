#include <stdio.h>
#include <stdlib.h>

void increase(int , int );

int main(int argc, char const *argv[])
{
  int n;
  printf("Masukkan nilai n = ");
  scanf("%d", &n);

  increase(0, n);
  return 0;
}

void increase(int i, int n){
  if (i > n)
    return;
  else
  {
    printf("%d\n", i);
    return increase(i + 1, n);
  }
}
