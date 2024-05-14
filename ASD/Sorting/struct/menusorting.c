#include "header.h"

void inputData_struct()
{
  printf("Masukkan data ke dalam array!\n");
  for (size_t i = 0; i < ARRAY_SIZE; i++)
  {
    printf("\nMasukkan no = ");
    scanf("%d", &data_siswa[i].no);
    getchar();
    printf("Masukkan nama = ");
    scanf("%s", data_siswa[i].nama);
    getchar();
    printf("Masukkan nilai = ");
    scanf("%d", &data_siswa[i].nilai);
    getchar();
    pdata[i] = &data_siswa[i].no;
  }
}

void select_sorting_method()
{
  int method;
  printf("MENU METODE SORTING :\n");
  printf("1. SELECTION\n");
  printf("2. INSERTION\n");
  printf("3. BUBBLE\n");
  printf("4. SHELL\n");
  printf("PILIHAN ANDA : ");
  scanf("%d", &method);
  switch (method)
  {
  case 1:
    selection();
    break;

  case 2:
    insertion();
    break;

  case 3:
    bubble();
    break;

  case 4:
    shell();
    break;

  default:
    break;
  }
}

int select_order()
{
  __uint8_t order;
  printf("\nMENU METODE PENGURUTAN SORTING :\n");
  printf("1. ASCENDING\n");
  printf("2. DESCENDING\n");
  printf("PILIHAN ANDA : ");
  scanf("%hhd", &order);
  return order < 4 ? order : 0;
}

int select_sort_by()
{
  __uint8_t sort_by;
  printf("\nMENU METODE PENGURUTAN BERDASARKAN :\n");
  printf("1. NO\n");
  printf("2. NAMA\n");
  printf("3. NILAI\n");
  printf("PILIHAN ANDA : ");
  scanf("%hhd", &sort_by);
  return sort_by < 4 ? sort_by : 0;
}

void printOutput()
{
  printf("\nNo.\tNama\tNilai\n");
  for (size_t i = 0; i < ARRAY_SIZE; i++)
  {
    printf("%d\t", data_siswa[i].no);
    printf("%s\t", data_siswa[i].nama);
    printf("%d\n", data_siswa[i].nilai);
  }
  printf("\n");
}

void swap(siswa *a, siswa *b)
{
  siswa temp = *a;
  *a = *b;
  *b = temp;
}