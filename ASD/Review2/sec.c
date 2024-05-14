#include "head.h"

node *head = NULL, *current;

void allocateOnIntOnly()
{
  current = (node *)malloc(sizeof(node));
  if (current == NULL)
  {
    printf("failed to allocate, please try again");
    exit(1);
  }
  printf("Masukkan data : ");
  scanf("%d", &current->data);
  getchar();
  current->next = NULL;
}

void printListOnIntOnly()
{
  node *temp;
  temp = head;
  printf("Data : \n");
  while (temp != NULL)
  {
    printf("%d  ", temp->data);
    temp = temp->next;
  }
  printf("\n");
}

void menuOnIntOnly()
{
  int choice;
  int exit = 0;
  while (!exit)
  {
    printf("PILIHAN\n1.Penambahan Data Secara Terurut\n2.Pencarian Data\n3.Penghapusan Data Tertentu\n4.Keluar\nMasukkan Pilihan Anda : ");
    scanf("%d", &choice);
    switch (choice)
    {
    case 1:
      autoInsert();
      break;
    case 2:
      findData();
      break;
    case 3:
      deleteNode();
      break;
    case 4:
      exit = 1;
      break;

    default:
      printf("invalid choice\n");
      break;
    }
    printListOnIntOnly();
  }
}

void allocateOnStruct()
{
  current = (node *)malloc(sizeof(node));
  if (current == NULL)
  {
    printf("failed to allocate, please try again");
    exit(1);
  }
  printf("Nomor\t: ");
  scanf("%d", &current->data);
  getchar();
  printf("Nama\t: ");
  fgets(current->nama, sizeof(current->nama), stdin);
  current->nama[strcspn(current->nama, "\n")] = 0;
  printf("Nilai\t: ");
  scanf("%f", &current->nilai);
  getchar();
  current->next = NULL;
}

void printListOnStruct()
{
  node *temp;
  temp = head;

  printf("\nNo\tNama\tNilai\n");
  while (temp != NULL)
  {
    printf("%d\t%s\t%.2f\n", temp->data, temp->nama, temp->nilai);
    temp = temp->next;
  }
  printf("\n");
}


void menuOnStruct()
{
  int choice;
  int exit = 0;
  while (!exit)
  {
    printf("PILIHAN\n1.Penambahan Data Secara Terurut\n2.Pencarian Data\n3.Penghapusan Data Tertentu\n4.Nilai Rata-Rata Kelas\nMasukkan Pilihan Anda : ");
    scanf("%d", &choice);
    switch (choice)
    {
    case 1:
      autoInsert();
      break;
    case 2:
      findData();
      break;
    case 3:
      deleteNode();
      break;
    case 4:
      findAverage();
      break;
    case 5:
      exit = 1;
      break;

    default:
      printf("invalid choice\n");
      break;
    }
    printListOnStruct();
  }
}
