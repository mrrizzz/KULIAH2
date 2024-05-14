#include "header.h"

void bubble()
{
  int order;
  order = select_order();
  int did_swap;
  int comparisons = 0, swaps = 0, shifts = 0;
  for (size_t i = ARRAY_SIZE; i > 1; i--)
  {
    
    did_swap = 0;
    for (size_t j = 1; j < ARRAY_SIZE; j++)
    {
      comparisons++;
      if (order == 1 ? data[j] < data[j - 1] : data[j] > data[j - 1])
      {
        swap(&data[j], &data[j - 1]);
        swaps++;
        shifts += 3;
        did_swap = 1;
      }
    }
    if (!did_swap)
      break;
    // else
    //   printOutput();
  }
  printf("Jumlah perbandingan = %d\n", comparisons);
  printf("Jumlah pergeseran = %d\n", shifts);
  printf("Jumlah pertukaran = %d\n", swaps);
}