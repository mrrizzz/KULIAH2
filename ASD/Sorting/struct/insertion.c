#include "header.h"

void insertion()
{
  int comparisons = 0;
  int shifts = 0;
  int swaps = 0;
  int did_swap;
  __uint8_t sort_by;
  __uint8_t order;

  order = select_order();
  sort_by = select_sort_by();

  for (size_t i = 1; i < ARRAY_SIZE; i++)
  {
    comparisons++;
    for (size_t j = i; j > 0; j--)
    {
      switch (sort_by)
      {
      case 1:
        if (order == 1 ? *pdata[j] < *pdata[j - 1] : *pdata[j] > *pdata[j - 1])
        {
          swap(&data_siswa[j], &data_siswa[j - 1]);
          swaps++;
          shifts += 3;
          did_swap = 1;
        }
        else
          break;
        break;
      case 2:
        if (order == 1 ? strcmp(data_siswa[j].nama, data_siswa[j - 1].nama) < 0 : strcmp(data_siswa[j].nama, data_siswa[j - 1].nama) > 0)
        {
          swap(&data_siswa[j], &data_siswa[j - 1]);
          swaps++;
          shifts += 3;
          did_swap = 1;
        }
        else
          break;
        break;
      case 3:
        if (order == 1 ? data_siswa[j].nilai < data_siswa[j - 1].nilai : data_siswa[j].nilai > data_siswa[j - 1].nilai)
        {
          swap(&data_siswa[j], &data_siswa[j - 1]);
          swaps++;
          shifts += 3;
          did_swap = 1;
        }
        else
          break;
        break;

      default:
        break;
      }
    }
  }
  printOutput();
  printf("Jumlah perbandingan = %d\n", comparisons);
  printf("Jumlah pergeseran = %d\n", shifts);
  printf("Jumlah pertukaran = %d\n", swaps);
}