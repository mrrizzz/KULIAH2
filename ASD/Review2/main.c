#include "head.h"

int intOnly;

int main(int argc, char const *argv[])
{
  printf("Integer Only? (1/0) ");
  scanf("%d", &intOnly);
  getchar();
  if (intOnly)
  {
    menuOnIntOnly();
  }else{
    menuOnStruct();
  }
  return 0;
}
