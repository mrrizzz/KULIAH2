// #include "../header.h"

// void init(stack *s)
// {
//   s->counter = 0;
// }
// int isFull(stack check)
// {
//   return check.counter >= MAX ? 1 : 0;
// }
// int isEmpty(stack check)
// {
//   return check.counter == 0 ? 1 : 0;
// }
// void push(stack *toPush)
// {
//   if (isFull(*toPush))
//   {
//     printf("Stack is full\n");
//     return;
//   }
//   else
//   {
//     printf("Masukkan pilihan anda : ");
//     scanf("%d", &toPush->content[toPush->counter]);
//     (toPush->counter)++;
//   }
// }

// void pop(stack *toPop)
// {
//   int temp;
//   if (isEmpty(*toPop))
//   {
//     printf("Stack is empty\n");
//     return;
//   }
//   else
//   {
//     (toPop->counter)--;
//     temp = toPop->content[toPop->counter];
//   }
// }

// void printStack(stack s)
// {
//   if (isEmpty(s))
//   {
//     printf("Stack is empty\n");
//     return;
//   }

//   printf("\nStack contents:\n");
//   for (int i = 0; i < s.counter; i++)
//   {
//     printf("%d\n", s.content[i]);
//   }
// }
