#include "header.h"

void insertion()
{
  int order;
  order = select_order();
  int comparisons = 0;
  int shifts = 0;
  int insertions = 0;


  for (size_t i = 1; i < ARRAY_SIZE; i++)
  {
    comparisons++;
    for (size_t j = i; j > 0; j--)
    {
      if (order == 1 ? data[j] < data[j - 1] : data[j] > data[j - 1])
      {
        swap(&data[j - 1], &data[j]);
        shifts++;
      }
      else
        break;
    }
    insertions++;
    // printOutput();
  }
  printf("Jumlah perbandingan = %d\n", comparisons);
  printf("Jumlah pergeseran = %d\n", shifts);
  printf("Jumlah penyisipan = %d\n", insertions);
}