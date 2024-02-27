#include "head.h"
//comment out the unused part
void awal()
{
    printf("\nSLL - INSERT DI AWAL\n");
    //BEGINNING OF SINGLE FUNCTION PURPOSES
    // int choice;
    // do
    // {
    //     alokasi();
    //     if (head != NULL)
    //     {
    //         current->next = head;
    //     }
    //     head = current;
    //     printf("Lagi (y/t)? ");
    //     choice = getchar();
    // } while (choice == 'y' || choice == 'Y');
    // tampil();
    // free_memory();
    // exit(1);
    //END OF SINGLE FUNCTION PURPOSES

    //BEGINNING OF MULTI FUNCTION PURPOSES
    alokasi();
    if (head != NULL)
    {
        current->next = head;
    }
    head = current;
    //END OF MULTI FUNCTION PURPOSES
}
