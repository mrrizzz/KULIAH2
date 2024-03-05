#include "../head.h"

void insert_akhir()
{
    node *tail;
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
    // clearScreen();
}
