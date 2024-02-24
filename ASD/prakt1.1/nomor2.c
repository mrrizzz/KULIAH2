#include <stdio.h>
#include <stdlib.h>
#include <string.h>

typedef struct info
{
  int id;
  char nama[40];
  int ttl[3];
  char gender;
  int gaji;
} Informasi;

void InputData(Informasi **, int *);
void PrintResult(Informasi *, int);
void clearScreen();

int main(int argc, char const *argv[])
{
  printf("DATA PEGAWAI\n\n");
  int jumlah_pegawai;
  Informasi *pegawai;

  InputData(&pegawai, &jumlah_pegawai);
  PrintResult(pegawai, jumlah_pegawai);
  return 0;
}

void InputData(Informasi **data, int *jumlah)
{
  printf("Berapa jumlah pegawai : ");
  scanf("%d", jumlah);
  getchar();

  *data = (Informasi *)malloc(*jumlah * (sizeof(Informasi)));
  if (*data == NULL)
  {
    printf("gagal alokasimemori\n");
  }

  for (int i = 0; i < *jumlah; i++)
  {
    printf("Data pegawai ke-%d\n", i + 1);
    printf("Nama \t\t\t: ");
    fgets((*data)[i].nama, sizeof((*data)[i].nama), stdin);
    (*data)[i].nama[strcspn((*data)[i].nama, "\n")] = 0;
    printf("Tgl lahir (dd-mm-yy)\t: ");
    scanf("%d-%d-%d", &(*data)[i].ttl[0], &(*data)[i].ttl[1], &(*data)[i].ttl[2]);
    getchar();
    printf("Jenis kelamin (L/P)\t: ");
    scanf("%c", &(*data)[i].gender);
    printf("Gaji/bulan \t\t: ");
    scanf("%d", &(*data)[i].gaji);
    getchar();
  }
  clearScreen();
}

void PrintResult(Informasi *data, int jumlah)
{
  printf("Data pegawai yang diinputkan \n\n");
  for (int i = 0; i < jumlah; i++)
  {
    printf("No ID \t\t: %d\n", i + 1);
    printf("Nama \t\t: %s\n", data[i].nama);
    printf("Tgl lahir \t: %d-%d-%d\n", data[i].ttl[0], data[i].ttl[1]), data[i].ttl[2];
    printf("Jenis Kelamin\t: %s\n", (data[i].gender == 'l' || data[i].gender == 'L') ? "Laki-laki " : "Perempuan");
    printf("Gaji/bulan \t: Rp.%d\n", data[i].gaji);
  }
}

void clearScreen()
{
#ifdef _WIN32
  system("cls"); // For Windows
#else
  printf("\033[2J\033[H"); // For Linux/Unix
#endif
}