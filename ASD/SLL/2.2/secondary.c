#include "head.h"

Siswa *head  = NULL, *current;
int failedInAfter;
int failedInBefore;

void alokasi()
{
    current = (Siswa *)malloc(sizeof(Siswa));
    if (current == NULL)
    {
        printf("gagal mengalokasikan memori\n");
        exit(1);
    }
    printf("\nNo\t: ");
    scanf("%d", &current->nomor);
    getchar();
    printf("Nama\t: ");
    fgets(current->nama, sizeof(current->nama), stdin);
    current->nama[strcspn(current->nama, "\n")] = 0;
    printf("Nilai\t: ");
    scanf("%d", &current->nilai);
    getchar();
    current->next = NULL;
}

void tampil()
{
    Siswa *baca;
    baca = head;
    printf("\nData dalam SLL :\n");
    while (baca != NULL)
    {
        printf("\nNo\t= %d\n", baca->nomor);
        printf("Nama\t= %s\n", baca->nama);
        printf("Nilai\t= %d\n", baca->nilai);
        baca = baca->next;
    }
    printf("\n");
}

void free_memory()
{
    Siswa *temp;
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
