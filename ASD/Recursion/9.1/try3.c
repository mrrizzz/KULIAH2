#include <stdio.h>
#include <stdlib.h>
#include <string.h>

void reverse(char *kal, int n);

int main(int argc, char const *argv[])
{
  char kal[100];
  printf("Masukkan kalimat = ");
  fgets(kal, sizeof(kal), stdin);
  int kal_size = strlen(kal);

  reverse(kal, kal_size);
  return 0;
}

void reverse(char *kal, int n)
{
  if (n < 0)
    return;
  else
  {
    printf("%c", kal[n]);
    return reverse(kal, n - 1);
  }
}
