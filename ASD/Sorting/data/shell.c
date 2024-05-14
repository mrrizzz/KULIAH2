#include "header.h"

void shell()
{
  int order;
  int did_swap;
  order = select_order();
  int comparisons = 0, swaps = 0, shifts = 0;

  int gap = ARRAY_SIZE / 2;
  while (gap >= 1)
  {
    did_swap = 1;
    while (did_swap)
    {
      did_swap = 0;
      int i = 0;
      while (i < (ARRAY_SIZE - gap))
      {
        comparisons++;
        if (order == 1 ? data[i] > data[i + gap] : data[i] < data[i + gap])
        {
          swap(&data[i], &data[i + gap]);
          swaps++;
          shifts += 3;
          did_swap = 1;
        }
        i++;
      }
      // printOutput();
      // printf("\n");
    }
    gap /= 2;
  }
  printf("Jumlah perbandingan = %d\n", comparisons);
  printf("Jumlah pergeseran = %d\n", shifts);
  printf("Jumlah pertukaran = %d\n", swaps);
}
