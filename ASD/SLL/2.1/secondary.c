#include "head.h"

Node *head  = NULL, *current;

void alokasi()
{
    current = (Node *)malloc(sizeof(Node));
    if (current == NULL)
    {
        printf("gagal mengalokasikan memori\n");
        exit(1);
    }
    printf("Nilai yang akan disimpan : ");
    scanf("%d", &current->data);
    getchar();
    current->next = NULL;
}

void tampil()
{
    Node *baca;
    baca = head;
    printf((failedInAfter == 1 || failedInBefore == 1) ? "gagal menemukan key, silahkan coba lagi\n" : "");
    printf("\nData dalam SLL :\n");
    while (baca != NULL)
    {
        printf("Nilai = %d\n", baca->data);
        baca = baca->next;
    }
    printf("\n");
}

void free_memory()
{
    Node *temp;
    while (head != NULL)
    {
        temp = head;
        head = head->next;
        free(temp);
    }
}

void clearScreen()
{
#ifdef _WIN32
    system("cls"); // For Windows
#else
    printf("\033[2J\033[H"); // For Linux/Unix
#endif
}
