#include "../polish.h"

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

void push(char content, stack *toPush)
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

char pop(stack *toPop)
{
  char temp;
  if (isEmpty(*toPop))
  {
    printf("Stack is empty\n");
    return '\0';
  }
  else
  {
    temp = toPop->content[--(toPop->counter)];
    return temp;
  }
}

void printStack(stack s)
{
  if (isEmpty(s))
  {
    printf("Stack is empty\n");
    return;
  }

  printf("\nStack contents:\n");
  for (int i = 0; i < s.counter; i++)
  {
    printf("%c\n", s.content[i]);
  }
}
int convert(char operator)
{
  switch (operator)
  {
  case '+':
  case '-':
    return 1;
    break;

  case '*':
  case '/':
    return 2;
    break;

  case '^':
    return 3;
    break;

  case '(':
    return 0;
    break;
  }
}
void polish()
{
  stack pol;
  char infix[10], postfix[20];
  int i = 0, j = 0;
  printf("MENGUBAH NOTASI INFIX MENJADI POSTFIX\n");
  printf("DENGAN MEMANFAATKAN STRUKTUR STACK\n\n");
  printf("Masukkan ekspresi dalam bentuk infix : ");
  scanf("%s", infix);
  init(&pol);
  while (infix[i] != '\0')
  {
    char ch = infix[i];
    if ((ch >= 'a' && ch <= 'z') || (ch >= 'A' && ch <= 'Z'))
      postfix[j++] = ch;
    else if ((ch >= '0' && ch <= '9'))
    {
      // Membaca operand
      int operand = 0;
      while ((ch >= '0' && ch <= '9'))
      {
        operand = operand * 10 + (ch - '0');
        ch = infix[++i];
      }
      i--; // Mundurkan indeks untuk membaca karakter berikutnya di iterasi berikutnya

      // Konversi operand integer ke string
      char operand_str[10];
      sprintf(operand_str, "%d", operand);
      // Menambahkan operand ke postfix sebagai string
      for (int k = 0; operand_str[k] != '\0'; k++)
      {
        postfix[j++] = operand_str[k];
      }
      postfix[j++] = ' '; // Memisahkan operand dari operator lainnya dalam postfix
    }
    else if (ch == '(')
      push(ch, &pol);
    else if (ch == ')')
    {
      while (!isEmpty(pol) && pol.content[pol.counter - 1] != '(')
        postfix[j++] = pop(&pol);
      postfix[j++] = ' ';
      pop(&pol);
    }
    else // operator
    {
      while (!isEmpty(pol) && (convert(ch) <= convert(pol.content[pol.counter - 1])))
        postfix[j++] = pop(&pol);
      push(ch, &pol);
    }
    i++;
  }
  while (!isEmpty(pol))
    postfix[j++] = pop(&pol);

  postfix[j] = '\0';
  printf("postfixx ==== %s", postfix);
}
