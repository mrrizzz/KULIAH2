#include "header.h"

void merge_rekursif(int left, int right, int order)
{
  if (left < right)
  {
    int mid = (left + right) / 2;
    merge_rekursif(left, mid, order);
    merge_rekursif(mid + 1, right, order);
    merge(left, mid, right, order);
  }
}

void merge(int left, int mid, int right, int order)
{
  int l1 = left;
  int r1 = mid;
  int l2 = mid + 1;
  int r2 = right;

  int i = left;

  while (l1 <= r1 && l2 <= r2)
  {
    if (order == 1 ? data[l1] <= data[l2] : data[l1] >= data[l2])
    {
      hasil[i] = data[l1];
      l1++;
    }else
    {
      hasil[i] = data[l2];
      l2++;
    }
    i++;
  }

  while (l1 <= r1)
  {
    hasil[i] = data[l1];
    l1++;
    i++;
  }

  while (l2  <= r2)
  {
    hasil[i] = data[l2];
    i++;
    l2++;
  }

  int j = left;
  
  while (j <= right)
  {
    data[j] = hasil[j];
    j++;
  }
  
  
}