#include <stdio.h>

typedef struct
{
  int day, month, year;
} Date;

int isYounger(Date, Date);

int main(int argc, char const *argv[])
{
  Date first_student, second_student;
  printf("Input the first student's birth date (dd-mm-yyyy): ");
  scanf("%d-%d-%d", &first_student.day, &first_student.month, &first_student.year);
  printf("Input the second student's birth date (dd-mm-yyyy): ");
  scanf("%d-%d-%d", &second_student.day, &second_student.month, &second_student.year);
  printf(isYounger(first_student, second_student) == 1 ? "Yes, student 1 is younger than student 2\n" : "No, student 1 is not younger than student 2\n");

  return 0;
}
int isYounger(Date student1, Date student2)
{
  if (student1.year < student2.year)
    return 1;
  else if (student1.year == student2.year)
  {
    if (student1.month < student2.month)
      return 1;
    else if (student1.month == student2.month)
    {
      if (student1.day < student2.day)
        return 1;
      else
        return 0;
    }
    else
      return 0;
  }
  else
    return 0;
}