#include <stdio.h>
#include <stdlib.h>

void decrease(int );

int main(int argc, char const *argv[])
{
  int n;
  printf("Masukkan nilai n = ");
  scanf("%d", &n);

  decrease(n);
  return 0;
}

void decrease(int n){
  if (n < 0)
    return;
  else
  {
    printf("%d\n", n);
    return decrease(n-1);
  }
  
}
