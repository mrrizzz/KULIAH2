#include "try4.h"

void menu_faktorial(int n, int hasil)
{
  clock_t t1, t2;
  long int delta_time;
  int pilihan;
  printf("Menu :\n1.Dengan Iterasi\n2.Dengan Rekursi\n3.Dengan Rekursi Tail\nMasukkan pilihan = ");
  scanf("%d", &pilihan);
  switch (pilihan)
  {
  case 1:

    time(&t1);
    printf("hasil = %d\n", iterasi_faktorial(n));
    time(&t2);
    printf("waktu komputasi = %f\n", difftime(t2, t1));
    break;
  case 2:
    time(&t1);
    printf("hasil = %d\n", rekursi_faktorial(n));
    time(&t2);
    printf("waktu komputasi = %f\n", difftime(t2, t1));
    break;
  case 3:
    time(&t1);
    printf("hasil = %d\n", rekursi_tail_faktorial(n, 1));
    time(&t2);
    printf("waktu komputasi = %f\n", difftime(t2, t1));
    break;
  default:
    break;
  }
}