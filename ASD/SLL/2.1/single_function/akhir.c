#include "../head.h"
//comment out the unused part
void akhir()
{
    Node *tail;
    printf("\nSLL - INSERT DI AKHIR\n");

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
    clearScreen();

    //END OF MULTI FUNCTION PURPOSES
}