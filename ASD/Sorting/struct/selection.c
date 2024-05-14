#include "header.h"

void selection()
{
  int marked_index;
  int comparisons = 0;
  int swaps = 0;
  int shifts = 0;
  int did_swap;
  __uint8_t sort_by;
  __uint8_t order;

  order = select_order();
  sort_by = select_sort_by();

  for (size_t i = 0; i < ARRAY_SIZE; i++)
  {
    marked_index = i;
    for (size_t j = i; j < ARRAY_SIZE; j++)
    {

      comparisons++;
      switch (sort_by)
      {
      case 1:
        if (order == 1 ? *pdata[j] < *pdata[marked_index] : *pdata[j] > *pdata[marked_index])
        {
          swap(&data_siswa[j], &data_siswa[marked_index]);
          swaps++;
          shifts += 3;
          did_swap = 1;
        }
        break;
      case 2:
        if (order == 1 ? strcmp(data_siswa[j].nama, data_siswa[marked_index].nama) < 0 : strcmp(data_siswa[j].nama, data_siswa[marked_index].nama) > 0)
        {
          swap(&data_siswa[j], &data_siswa[marked_index]);
          swaps++;
          shifts += 3;
          did_swap = 1;
        }
        break;
      case 3:
        if (order == 1 ? data_siswa[j].nilai < data_siswa[marked_index].nilai : data_siswa[j].nilai > data_siswa[marked_index].nilai)
        {
          swap(&data_siswa[j], &data_siswa[marked_index]);
          swaps++;
          shifts += 3;
          did_swap = 1;
        }
        break;

      default:
        break;
      }
      // if (order == 1 ? *pdata[j] < *pdata[marked_index] : *pdata[j] > *pdata[marked_index])
      //   marked_index = j;
    }
    swap(&data_siswa[marked_index], &data_siswa[i]);
    swaps++;
  }
  printOutput();
  printf("Jumlah perbandingan = %d\n", comparisons);
  printf("Jumlah pertukaran = %d\n", swaps);
}
