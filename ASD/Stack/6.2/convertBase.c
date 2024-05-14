#include "../convert.h"

void init(stack *s)
{
  s->counter = 0;
}
int isFull(stack check)
{
  return check.counter >= MAX;
}
int isEmpty(stack check)
{
  return check.counter == 0;
}

void push(int content, stack *toPush)
{
  if (isFull(*toPush))
  {
    printf("Stack is full\n");
    return;
  }
  else
  {
    toPush->content[toPush->counter] = content;
    toPush->counter++;
  }
}

int pop(stack *toPop)
{
  int temp;
  if (isEmpty(*toPop))
  {
    printf("Stack is empty\n");
    return 0;
  }
  else
  {
    temp = toPop->content[--(toPop->counter)];
    return temp;
  }
}

void printStack(stack number)
{
  while (!isEmpty(number))
  {
    printf("%x", pop(&number));
  }
  printf("\n");
}

void convertToBinary(stack number, int input)
{
  int temp;
  while (input > 0)
  {
    temp = input % 2;
    push(temp, &number);
    input /= 2;
  }
  printStack(number);
}
void convertToOctal(stack number, int input)
{
  int temp;
  while (input > 0)
  {
    temp = input % 8;
    push(temp, &number);
    input /= 8;
  }
  printStack(number);
}
void convertToHexadecimal(stack number, int input)
{
  int temp;
  while (input > 0)
  {
    temp = input % 16;
    push(temp, &number);
    input /= 16;
  }
  printStack(number);
}

void inputNumber()
{
  stack number;
  init(&number);
  int input, choice;
  int exit = 0;
  printf("KONVERSI BILANGAN DESIMAL\nMasukkan bil desimal yang akan dikonversi : ");
  scanf("%d", &input);
  while (!exit)
  {
    printf("MENU KONVERSI :\n1. BINER\n2.OKTAL\n3.HEKSADEWSIMAL\n4.KELUAR\n\n");
    printf("Masukkan pilihan anda :  ");
    scanf("%d", &choice);
    switch (choice)
    {
    case 1:
      printf("Hasil konversi dari %d ke BINER = ", input);
      convertToBinary(number, input);
      break;

    case 2:
      printf("Hasil konversi dari %d ke OCTAL = ", input);
      convertToOctal(number, input);
      break;

    case 3:
      printf("Hasil konversi dari %d ke HEKSADESIMAL = ", input);
      convertToHexadecimal(number, input);
      break;

    case 4:
      exit = 1;
      break;

    default:
      printf("INVALID CHOICES");
      break;
    }
  }
}
