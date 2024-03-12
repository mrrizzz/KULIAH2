#include "../head.h"

void delete_akhir()
{
    node *tail, *before_tail;
    
    if (head == NULL)
        return;

    if (head->next == NULL)
        delete_awal();
    else
    {
        tail = head;
        before_tail = NULL;
        while (tail->next != NULL)
        {
            before_tail = tail;
            tail = tail->next;
        }
        before_tail->next = NULL;
        free_node(tail);
    }
}
