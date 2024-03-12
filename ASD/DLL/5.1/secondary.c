#include "header.h"

node *head = NULL;
node *newNode;

void allocate()
{
  newNode = (node *)malloc(sizeof(node));
  if (newNode == NULL)
  {
    printf("failed to allocate memory\n");
    exit(1);
  }
  printf("New Data : ");
  scanf("%d", &newNode->data);
  getchar();
  newNode->next = NULL;
  newNode->prev = NULL;
}

void printList()
{
  node *temp;
  temp = head;

  printf("\nDLL Data :\n");
  while (temp != NULL)
  {
    printf("%d\n", temp->data);
    temp = temp->next;
  }
  printf("\n");
}

void freeNode(node *toFree)
{
  free(toFree);
  toFree = NULL;
}

void insertLoopingCheck(void (*insertChoice)(), const char *message)
{
  printf("\nInsert in the %s of Linked List\n", message);
  char choice;
  do
  {
    insertChoice();
    printf("Again? (y/t) : ");
    choice = getchar();
  } while (choice == 'y' || choice == 'Y');
}

void insertOnlyMenu(const char *option)
{
  int exit;
  int menu;

  if (strcmp(option, "single") == 0)
  {
    printf("1. Prepend\n2. Append\n3. Insert After\n4. Insert Before\n");
    printf("Choose Menu : ");
    scanf("%d", &menu);
    switch (menu)
    {
    case 1:
      insertLoopingCheck(prepend, "beginning");
      break;
    case 2:
      insertLoopingCheck(append, "end");
      break;
    case 3:
      insertLoopingCheck(append, "end");
      insert("after");
      break;
    case 4:
      insertLoopingCheck(append, "end");
      insert("before");
      break;
    default:
      printf("Invalid choices\n");
      break;
    }
  }
  else
  {
    exit = 0;
    while (!exit)
    {
      printf("Menu Insert\n1. Prepend\n2. Append\n3. Insert After\n4. Insert Before\n0. Exit\n");
      printf("Choose Menu : ");
      scanf("%d", &menu);
      switch (menu)
      {
      case 1:
        prepend();
        break;
      case 2:
        append();
        break;
      case 3:
        insert("after");
        break;
      case 4:
        insert("before");
        break;
      case 0:
        exit = 1;
        break;
      default:
        printf("Invalid choices\n");
        break;
      }
      printList();
    }
  }
}

void insertMenu()
{
  int menu;
  printf("\nMenu Insert\n1. Prepend\n2. Append\n3. Insert After\n4. Insert Before\n0. Exit\n");
  printf("Choose Menu : ");
  scanf("%d", &menu);
  switch (menu)
  {
  case 1:
    prepend();
    break;
  case 2:
    append();
    break;
  case 3:
    insert("after");
    break;
  case 4:
    insert("before");
    break;

  default:
    printf("Invalid choices\n");
    break;
  }
}

void deleteMenu()
{
  int menu;
  printf("\nMenu Delete\n1. Delete Head\n2. Delete Tail\n3. Delete Specific\n0. Exit\n");
  printf("Choose Menu : ");
  scanf("%d", &menu);
  switch (menu)
  {
  case 1:
    deleteHead();
    break;
  case 2:
    deleteTail();
    break;
  case 3:
    deleteSpecific();
    break;
  default:
    printf("Invalid choices\n");
    break;
  }
}

void insertDeleteMenu()
{
  int menu;
  int exit = 0;

  while (!exit)
  {
    printf("Menu Utama\n1. Insert\n2. Delete\n3. Exit\n");
    printf("Choose Menu : ");
    scanf("%d", &menu);
    switch (menu)
    {
    case 1:
      insertMenu();
      break;
    case 2:
      deleteMenu();
      break;
    case 3:
      exit = 1;
      break;
    default:
      printf("Invalid choices\n");
      ;
      break;
    }
    printList();
  }
}