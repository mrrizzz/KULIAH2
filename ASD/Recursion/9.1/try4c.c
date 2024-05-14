#include "try4.h"

int rekursi_tail_faktorial(int n, int hasil)
{
  if (n == 1)
    return hasil;
  else
    return rekursi_tail_faktorial(n - 1,n * hasil);
}