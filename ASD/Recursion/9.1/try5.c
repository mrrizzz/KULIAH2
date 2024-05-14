#include <stdio.h>

int kombinasi(int, int);
int permutasi(int, int);
int faktorial(int);

int main(int argc, char const *argv[])
{
  int n, k;
  printf("Masukkan n = ");
  scanf("%d", &n);

  printf("Masukkan k = ");
  scanf("%d", &k);

  printf("Hasil kombinasi = %d\n", kombinasi(n, k));
  printf("Hasil permutasi = %d\n", permutasi(n, k));
  return 0;
}

int kombinasi(int n, int k)
{
  return faktorial(n) / (faktorial(k) * faktorial(n - k));
}

int permutasi(int n, int k)
{
  return faktorial(n) / faktorial(n - k);
}

int faktorial(int n)
{
  if (n == 1)
    return 1;
  else
    return n * faktorial(n - 1);
}