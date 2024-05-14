#include "try4.h"

int rekursi_faktorial(int n)
{
  if (n == 1)
    return 1;
  else
    return n * rekursi_faktorial(n - 1);
}