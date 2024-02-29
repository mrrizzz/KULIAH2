#include "../head.h"

int main(int argc, char const *argv[])
{
    char choice;
    int insert_choice;
    printf("SINGLE LINKED LIST INSERT\n");
    printf("SINGLE FUNCTION MODE : \n1. FRONT\n2.END\n3.AFTER\n4.BEFORE\n");
    printf("INPUT YOUR CHOICE : ");
    scanf("%d", &insert_choice);

    switch (insert_choice)
    {
    case 1:
        printf("Linked list untuk aplikasi INSERT DI AWAL\n");
        do
        {
            awal();
            printf("Lagi? (y/t) : ");
            choice = getchar();
        } while (choice == 'y' || choice == 'Y');
        break;
    case 2:
        printf("Linked list untuk aplikasi INSERT DI AKHIR\n");
        do
        {
            akhir();
            printf("Lagi? (y/t) : ");
            choice = getchar();
        } while (choice == 'y' || choice == 'Y');
        break;
    case 3:
        printf("Linked list untuk aplikasi INSERT SETELAH NILAI TERTENTU\n");
        do
        {
            akhir();
            after();
            printf("Lagi? (y/t) : ");
            choice = getchar();
        } while (choice == 'y' || choice == 'Y');
        break;
    case 4:
        printf("Linked list untuk aplikasi INSERT SEBELUM NILAI TERTENTU\n");
        do
        {
            akhir();
            before();
            printf("Lagi? (y/t) : ");
            choice = getchar();
        } while (choice == 'y' || choice == 'Y');
        break;
    default:
        break;
    }
    clearScreen();
    tampil();
    free_memory();
    return 0;
}
