#include "../head.h"
//comment out the unused part
void awal()
{
    printf("\nSLL - INSERT DI AWAL\n");

    //BEGINNING OF MULTI FUNCTION PURPOSES
    alokasi();
    if (head != NULL)
    {
        current->next = head;
    }
    head = current;
    clearScreen();

    //END OF MULTI FUNCTION PURPOSES
}
