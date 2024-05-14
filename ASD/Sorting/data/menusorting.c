#include "header.h"

void inputData()
{
  printf("Masukkan data ke dalam array!\n");
  for (size_t i = 0; i < ARRAY_SIZE; i++)
  {
    printf("Masukkan data ke %ld = ", i + 1);
    scanf("%d", &data[i]);
  }
}

double select_sorting_method()
{
  int method;
  printf("MENU METODE SORTING :\n");
  printf("1. SELECTION\n");
  printf("2. INSERTION\n");
  printf("3. BUBBLE\n");
  printf("4. SHELL\n");
  printf("5. MERGE\n");
  printf("6. QUICK\n");
  printf("0. KELUAR\n");
  printf("PILIHAN ANDA : ");
  scanf("%d", &method);

  switch (method)
  {
  case 1:
    return operation_time(selection);
    break;

  case 2:
    return operation_time(insertion);
    break;

  case 3:
    return operation_time(bubble);
    break;

  case 4:
    return operation_time(shell);
    break;

  case 5:
    return operation_time(merge_rekursif_wrapper);
    break;

  case 6:
    return operation_time(quick_wrapper);
    break;

  case 0:
    exit(1);
    break;

  default:
    break;
  }

}

void generate(int data[], int n)
{
  srand(time(NULL));
  for (int i = 0; i < n; i++)
  {
    data[i] = rand() % 100000;
  }
}

double operation_time(void (*func)())
{
  clock_t start, end;
  double waktu_komputasi;
  start = clock();
  func();
  end = clock();
  waktu_komputasi = ((double)(end - start)) / CLOCKS_PER_SEC;
  return waktu_komputasi;
}

int select_order()
{
  int order;
  printf("MENU METODE PENGURUTAN SORTING :\n");
  printf("1. ASCENDING\n");
  printf("2. DESCENDING\n");
  printf("PILIHAN ANDA : ");
  scanf("%d", &order);
  return order;
}

void swap(int *a, int *b)
{
  int temp = *a;
  *a = *b;
  *b = temp;
}

void backup(int new[], int origin[], int n)
{
  for (size_t i = 0; i < n; i++)
  {
    new[i] = origin[i];
  }
}

void printOutput()
{
  for (size_t i = 0; i < ARRAY_SIZE; i++)
  {
    printf("%d ", data[i]);
  }
  printf("\n");
}

void merge_rekursif_wrapper() {
  int order = select_order();
  merge_rekursif(0, ARRAY_SIZE - 1, order);
}

void quick_wrapper() {
  int order = select_order();
  quick(0, ARRAY_SIZE - 1, order);
}
