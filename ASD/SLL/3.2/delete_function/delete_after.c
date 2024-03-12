#include "../head.h"

void delete_after()
{
    node *find_key, *toDelete;
    int key;

    if (head == NULL || head->next == NULL)
    {
        printf("Linked list kosong atau hanya memiliki satu node.\n");
        return;
    }
    printf("Hapus nilai setelah nilai ... ");
    scanf("%d", &key);

    find_key = head;
    is_delete_key_found = 1;

    while (find_key != NULL && find_key->no != key)
        find_key = find_key->next;
    
    if (find_key == NULL || find_key->next == NULL)
    {
        printf("Key not found or it's the last node\n");
        is_delete_key_found = 0;
        return;
    }
    
    toDelete = find_key->next;
    find_key->next = find_key->next->next;
    free_node(toDelete);
}