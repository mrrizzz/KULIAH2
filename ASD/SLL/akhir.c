#include "head.h"
//comment out the unused part
void akhir()
{
    Node *tail;
    printf("\nSLL - INSERT DI AKHIR\n");
    // BEGINNING OF SINGLE FUNCTION PURPOSES
    // int choice;
    // do
    // {
    //     alokasi();
    //     if (head == NULL)
    //         head = current;
    //     else
    //     {
    //         tail = head;
    //         while (tail->next != NULL)
    //             tail = tail->next;
    //         tail->next = current;
    //     }
    //     printf("Lagi (y/t)? ");
    //     choice = getchar();
    // } while (choice == 'y' || choice == 'Y');
    // tampil();
    // free_memory();
    // // exit(1); //comment out exit when using after or before function! (single function purposes)
    // END OF SINGLE FUNCTION PURPOSES

    //BEGINNING OF MULTI FUNCTION PURPOSES
    alokasi();
    if (head == NULL)
        head = current;
    else
    {
        tail = head;
        while (tail->next != NULL)
            tail = tail->next;
        tail->next = current;
    }
    //END OF MULTI FUNCTION PURPOSES
}