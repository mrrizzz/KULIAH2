#include <stdlib.h>
#include <string.h>
#include <stdio.h>

typedef struct data
{
  char nama[50];
  float nilai_tugas;
  float nilai_uts;
  float nilai_uas;
  float nilai_akhir;
  char grade;
} Data;

void PrintLine();
void InputData(int *, Data **);
char GetGrade(float);
void PrintResult(int, Data *);
void clearScreen();

int main(int argc, char const *argv[])
{
  int jumlah_mahasiswa;
  Data *mahasiswa;
  InputData(&jumlah_mahasiswa, &mahasiswa);
  PrintResult(jumlah_mahasiswa, mahasiswa);

  free(mahasiswa);
  mahasiswa = NULL;
  return 0;
}

void InputData(int *jumlah, Data **data)
{
  printf("MENGHITUNG NILAI AKHIR \nMATA KULIAH KONSEP PEMROGRAMAN\n\n");
  printf("Berapa jumlah mahasiswa ? ");
  scanf("%d", jumlah);
  getchar();

  *data = (Data *)malloc(*jumlah * sizeof(Data));

  if (*data == NULL)
    printf("gagal mengalokasikan memori\n");

  printf("MASUKKAN DATA MAHASISWA\n\n");
  for (int i = 0; i < *jumlah; i++)
  {
    printf("Mahasiswa ke - %d\n", i + 1);
    printf("Nama : ");
    fgets((*data)[i].nama, sizeof((*data)[i].nama), stdin);
    (*data)[i].nama[strcspn((*data)[i].nama, "\n")] = 0;
    printf("Nilai Tugas : ");
    scanf("%f", &(*data)[i].nilai_tugas);
    printf("Nilai UTS : ");
    scanf("%f", &(*data)[i].nilai_uts);
    printf("Nilai UAS : ");
    scanf("%f", &(*data)[i].nilai_uas);
    getchar();
    (*data)[i].nilai_akhir = (*data)[i].nilai_tugas * 0.2 + (*data)[i].nilai_uts * 0.4 + (*data)[i].nilai_uas * 0.4;
    (*data)[i].grade = GetGrade((*data)[i].nilai_akhir);
  }
  clearScreen();
}

void PrintResult(int jumlah, Data *data)
{
  printf("\t\t\t\tDAFTAR NILAI\n");
  printf("\t\t\tMATAKULIAH KONSEP PEMROGRAMAN\n");
  PrintLine();

  printf("No\tNama\t\t\tNilai\t\t\tGrade\n");
  printf("\tMahasiswa\tTugas\tUTS\tUAS\tAkhir\n");
  PrintLine();

  for (int i = 0; i < jumlah; i++)
  {
    printf("%d\t%s\t\t%.1f\t%.1f\t%.1f\t%.1f\t%c\n", i + 1, data[i].nama, data[i].nilai_tugas, data[i].nilai_uts, data[i].nilai_uas, data[i].nilai_akhir, data[i].grade);
  }
}

char GetGrade(float akhir)
{
  if (akhir >= 80)
    return 'A';
  else if (akhir >= 70 && akhir < 80)
    return 'B';
  else if (akhir >= 60 && akhir < 70)
    return 'C';
  else if (akhir >= 50 && akhir < 60)
    return 'D';
  else
    return 'E';
}

void PrintLine()
{
  for (int i = 0; i < 80; i++)
  {
    printf("-");
  }
  printf("\n");
}

void clearScreen()
{
#ifdef _WIN32
  system("cls"); // For Windows
#else
  printf("\033[2J\033[H"); // For Linux/Unix
#endif
}
