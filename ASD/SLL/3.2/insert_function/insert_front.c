#include "../head.h"

void insert_awal()
{
    alokasi();
    if (head != NULL)
    {
        current->next = head;
    }
    head = current;
    // clearScreen();
}
