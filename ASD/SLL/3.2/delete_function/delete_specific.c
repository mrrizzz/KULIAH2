#include "../head.h"

void delete_specific()
{
    node *find_key, *before_key = NULL;
    int key;

    printf("Hapus nilai... ");
    scanf("%d", &key);

    find_key = head;
    is_delete_key_found = 1;
    while (find_key != NULL && find_key->no != key)
    {
        before_key = find_key;
        find_key = find_key->next;
    }
    if (find_key == NULL){
        printf("\nkey tidak ditemukan\n");
        is_delete_key_found = 0;
    }
    else
    {
        if (head->next == NULL)
            delete_awal();
        else
        {
            if (before_key == NULL)
                head = head->next;
            else
                before_key->next = find_key->next;

            free_node(find_key);
        }
    }
}