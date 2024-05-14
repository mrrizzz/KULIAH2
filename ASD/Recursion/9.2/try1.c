#include <stdio.h>

int fpb(int, int);

int main(int argc, char const *argv[])
{
  int x, y;
  int result;

  printf("Inputkan bilangan x = ");
  scanf("%d", &x);
  printf("Inputkan bilangan y = ");
  scanf("%d", &y);

  printf("Hasil FPB dari %d dan %d = %d\n", x, y, fpb(x, y));
  return 0;
}

int fpb(int x, int y)
{
  if (y == 0)
  {
    return x;
  }
  else
  {
    return fpb(y, x % y);
  }
}
