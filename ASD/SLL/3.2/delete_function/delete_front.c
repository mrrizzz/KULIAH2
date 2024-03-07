#include "../head.h"

void delete_awal()
{ 
    node *temp;
    temp = head;
    head = head->next;
    free_node(temp);
}