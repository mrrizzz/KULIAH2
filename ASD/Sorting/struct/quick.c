#include "header.h"

void quicksort(int left, int right, int order, int sort_by)
{
  if (left < right)
  {
    int pivot = partition(left, right, order, sort_by);
    quicksort(left, pivot, order, sort_by);
    quicksort(pivot + 1, right, order, sort_by);
  }
}

int partition(int left, int right, int order, int sort_by)
{
  siswa temp_pivot = data_siswa[left];
  int i = left - 1;
  int j = right + 1;

  while (1)
  {
    if (order == 1)
    { // Ascending
      switch (sort_by)
      {
      case 1:
        do
        {
          i++;
        } while (data_siswa[i].no < temp_pivot.no);
        do
        {
          j--;
        } while (data_siswa[j].no > temp_pivot.no);
        break;
      case 2:
        do
        {
          i++;
        } while (strcmp(data_siswa[i].nama, temp_pivot.nama) < 0);
        do
        {
          j--;
        } while (strcmp(data_siswa[j].nama, temp_pivot.nama) > 0);
        break;
      case 3:
        do
        {
          i++;
        } while (data_siswa[i].nilai < temp_pivot.nilai);
        do
        {
          j--;
        } while (data_siswa[j].nilai > temp_pivot.nilai);
        break;
      }
    }
    else
    { // Descending
      switch (sort_by)
      {
      case 1:
        do
        {
          i++;
        } while (data_siswa[i].no > temp_pivot.no);
        do
        {
          j--;
        } while (data_siswa[j].no < temp_pivot.no);
        break;
      case 2:
        do
        {
          i++;
        } while (strcmp(data_siswa[i].nama, temp_pivot.nama) > 0);
        do
        {
          j--;
        } while (strcmp(data_siswa[j].nama, temp_pivot.nama) < 0);
        break;
      case 3:
        do
        {
          i++;
        } while (data_siswa[i].nilai > temp_pivot.nilai);
        do
        {
          j--;
        } while (data_siswa[j].nilai < temp_pivot.nilai);
        break;
      }
    }

    if (i >= j)
    {
      return j;
    }

    swap(&data_siswa[i], &data_siswa[j]);
  }
}

void quick_wrapper()
{
  int sort_by = select_sort_by();
  int order = select_order();
  quicksort(0, ARRAY_SIZE - 1, order, sort_by);
}
