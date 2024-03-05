#include "head.h"

node *head = NULL, *current;
int failed_in_after;
int failed_in_before;

void main_menu()
{
    int exit = 0;
    int main_choice;
    while (!exit)
    {
        printf("Menu SLL\n1. INSERT\n2. DELETE\n3. EXIT\n");
        printf("Masukkan pilihan : ");
        scanf("%d", &main_choice);

        switch (main_choice)
        {
        case 1:
            menu_insert();
            break;
        case 2:
            if (head == NULL)
                printf("SLL masih kosong, tidak bisa delete!!!\n");
            else
                menu_delete();
            break;
        case 3:
            exit = 1;
            break;
        default:
            clearScreen();
            printf("Pilihan anda tadi tidak valid, silahkan coba lagi\n");
            break;
        }
        tampil();
    }
}

void insert_looping_check(void (*insert)())
{
    char choice;
    do
    {
        insert();
        printf("Lagi? (y/t) : ");
        choice = getchar();
    } while (choice == 'y' || choice == 'Y');
}

void delete_single_looping_option(void (*delete)(), const char *delete_message)
{
    insert_looping_check(insert_akhir);
    tampil();
    while (head != NULL)
    {
        delete();
        printf("%s", delete_message);
        tampil();
    }
}

void alokasi()
{
    current = (node *)malloc(sizeof(node));
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
    node *baca;
    baca = head;
    printf((failed_in_after == 1 || failed_in_before == 1) ? "gagal menemukan key, silahkan coba lagi\n" : "");
    printf("\nData dalam SLL :\n");
    if (head == NULL)
        printf("Kosong\n");
    else
    {
        while (baca != NULL)
        {
            printf("Nilai = %d\n", baca->data);
            baca = baca->next;
        }
        // printf("\n");
    }
}

void free_memory()
{
    node *temp;
    while (head != NULL)
    {
        temp = head;
        head = head->next;
        free(temp);
    }
}

void free_node(node *deleted)
{
    free(deleted);
    deleted = NULL;
}

void clearScreen()
{
#ifdef _WIN32
    system("cls"); // For Windows
#else
    printf("\033[2J\033[H"); // For Linux/Unix
#endif
}
