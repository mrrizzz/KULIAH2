#include <stdio.h>

typedef struct
{
  int day, month, year;
} Date;

int sameDay(Date, Date);

int main(int argc, char const *argv[])
{
  Date first_date, second_date;
  printf("Masukkan tanggal pertama (dd-mm-yyyy): ");
  scanf("%d-%d-%d", &first_date.day, &first_date.month, &first_date.year);
  printf("Masukkan tanggal kedua (dd-mm-yyyy): ");
  scanf("%d-%d-%d", &second_date.day, &second_date.month, &second_date.year);
  printf(sameDay(first_date, second_date) == 1 ? "It is the same day\n" : "It is not the same day\n");

  return 0;
}

int sameDay(Date first_date, Date second_date)
{
  return (first_date.day == second_date.day && first_date.month == second_date.month && first_date.year == second_date.year) ? 1 : 0;
}
