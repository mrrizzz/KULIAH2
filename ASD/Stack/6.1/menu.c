#include "../header.h"

void menu()
{
  stack trial;
  int choice;
  int exit = 0;
  trial.counter = 0;
  while (!exit)
  {
    printf("\nMENU STACK USING ARRAY : \n1. PUSH\n2. POP\n3. PRINT STACK\n4. EXIT\n");
    printf("Input menu : ");
    scanf("%d", &choice);
    switch (choice)
    {
    case 1:
      push(&trial);
      break;
    case 2:
      pop(&trial);
      break;
    case 3:
      printStack(trial);
      break;
    case 4:
      exit = 1;
      break;
    default:
      printf("Invalid Choice\n");
      break;
    }
  }
}

