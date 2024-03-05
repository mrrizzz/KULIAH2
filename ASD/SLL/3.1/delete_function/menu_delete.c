#include "../head.h"

void menu_delete_single()
{
    int delete_choice;
    printf("SINGLE LINKED LIST DELETE\n");
    printf("1.FRONT\n2.END\n3.SPECIFIC\nYOUR CHOICE : ");
    scanf("%d", &delete_choice);
    switch (delete_choice)
    {
    case 1:
        delete_single_looping_option(delete_awal, "Menghapus data posisi awal...");
        break;
    case 2:
        delete_single_looping_option(delete_akhir, "Menghapus data posisi akhir...");
        break;
    case 3:
        delete_single_looping_option(delete_specific, "Menghapus data posisi tertentu...");
        break;
    case 0:
        break;
    default:
        printf("invalid choices\n");
        break;
    }
}

void menu_delete()
{
    int delete_choice;
    printf("Menu Delete\n");
    printf("1.FRONT\n2.END\n3.SPECIFIC\nYOUR CHOICE : ");
    scanf("%d", &delete_choice);

    switch (delete_choice)
    {
    case 1:
        delete_awal();
        printf("\nMenghapus data posisi awal...");
        break;
    case 2:
        delete_akhir();
        printf("\nMenghapus data posisi akhir...");
        break;
    case 3:
        delete_specific();
        printf("\nMenghapus data posisi tertentu...");
        break;
    case 0:
        return;
        break;
    default:
        clearScreen();
        printf("invalid choices\n");
        break;
    }
}