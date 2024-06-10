#include "header.h"

void quick(int left, int right, int order) {
  if (left < right) {
    int pivot = quick_partition(left, right, order);
    quick(left, pivot, order);
    quick(pivot + 1, right, order);
  }
}

int quick_partition(int left, int right, int order) {
  int temp_pivot = data[left];
  int i = left - 1;
  int j = right + 1;
  while (i < j) {
    if (order == 1) { // Mode ascending
      do {
        i++;
      } while (data[i] < temp_pivot && i <= right);

      do {
        j--;
      } while (data[j] > temp_pivot && j >= left);
    } else { // Mode descending
      do {
        i++;
      } while (data[i] > temp_pivot && i <= right);

      do {
        j--;
      } while (data[j] < temp_pivot && j >= left);
    }
    if (i >= j)
      return j;

    swap(&data[i], &data[j]);
  }
}
