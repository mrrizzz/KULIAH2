#include "header.h"

void shell()
{
  int did_swap;
  __uint8_t sort_by;
  __uint8_t order;

  order = select_order();
  sort_by = select_sort_by();

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
        switch (sort_by)
        {
        case 1:
          if (order == 1 ? *pdata[i] > *pdata[i + gap] : *pdata[i] < *pdata[i + gap])
          {
            swap(&data_siswa[i], &data_siswa[i + gap]);
            swaps++;
            shifts += 3;
            did_swap = 1;
          }
          break;
        case 2:
          if (order == 1 ? strcmp(data_siswa[i].nama, data_siswa[i + gap].nama) < 0 : strcmp(data_siswa[i].nama, data_siswa[i + gap].nama) > 0)
          {
            swap(&data_siswa[i], &data_siswa[i + gap]);
            swaps++;
            shifts += 3;
            did_swap = 1;
          }
          break;
        case 3:
          if (order == 1 ? data_siswa[i].nilai > data_siswa[i + gap].nilai : data_siswa[i].nilai < data_siswa[i + gap].nilai)
          {
            swap(&data_siswa[i], &data_siswa[i + gap]);
            swaps++;
            shifts += 3;
            did_swap = 1;
          }
          break;

        default:
          break;
        }
        // if (order == 1 ? *pdata[i] > *pdata[i + gap] : *pdata[i] < *pdata[i + gap])
        // {
        //   swap(&data_siswa[i], &data_siswa[i + gap]);
        //   swaps++;
        //   shifts += 3;
        //   did_swap = 1;
        // }
        i++;
      }
    }
    gap /= 2;
  }
  printOutput();
  printf("Jumlah perbandingan = %d\n", comparisons);
  printf("Jumlah pergeseran = %d\n", shifts);
  printf("Jumlah pertukaran = %d\n", swaps);
}
