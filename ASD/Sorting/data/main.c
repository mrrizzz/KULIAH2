#include "header.h"

int data[ARRAY_SIZE];
int hasil[ARRAY_SIZE];

int main(int argc, char const *argv[])
{
  int input_array;
  double total_computational_time;
  int backup_data[ARRAY_SIZE];

  printf("Beraoa jumlah data (maks 100000) ? ");
  scanf("%d", &input_array);
  generate(backup_data, input_array);

  while (1)
  {
    backup(data, backup_data, input_array);
    total_computational_time = select_sorting_method();
    printf("durasi = %f\n\n", total_computational_time);
  }

  return 0;
}