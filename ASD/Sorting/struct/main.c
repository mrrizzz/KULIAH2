#include "header.h"

siswa data_siswa[ARRAY_SIZE];
int *pdata[ARRAY_SIZE];

int main(int argc, char const *argv[])
{
  inputData_struct();
  while (1)
  {
    menu_searching();
  }
  
  return 0;
}