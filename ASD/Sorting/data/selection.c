#include "header.h"

void selection()
{
  int order;
  int marked_index;
  int comparisons = 0;
  int swaps = 0;

  order = select_order();

  for (size_t i = 0; i < ARRAY_SIZE; i++)
  {
    marked_index = i;
    for (size_t j = i; j < ARRAY_SIZE; j++)
    {
      comparisons++;
      if (order == 1 ? data[j] < data[marked_index] : data[j] > data[marked_index])
        marked_index = j;
    }
    swap(&data[marked_index], &data[i]);
    swaps++;
    // printOutput();
  }
  printf("Jumlah perbandingan = %d\n", comparisons);
  printf("Jumlah pertukaran = %d\n", swaps);
}
