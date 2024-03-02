#include "../head.h"

void awal()
{
    alokasi();
    if (head != NULL)
    {
        current->next = head;
    }
    head = current;
    clearScreen();
}
