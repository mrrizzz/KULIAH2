#include "try4.h"

int iterasi_faktorial(int n)
{
  long hasil = 1;
  while (n > 0)
  {
    hasil = hasil * n;
    n--;
  }

  return hasil;
}