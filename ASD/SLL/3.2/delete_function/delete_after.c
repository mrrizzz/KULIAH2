#include "../head.h"

int is_delete_after_end;

void delete_after()
{
    node *find_key, *after_key;
    int key;

    if (head == NULL || head->next == NULL)
    {
        printf("Linked list kosong atau hanya memiliki satu node.\n");
        return;
    }

    printf("Hapus nilai setelah nilai ... ");
    scanf("%d", &key);

    find_key = head;
    after_key = find_key->next;
    is_delete_key_found = 1;
    is_delete_after_end = 0;

    while (find_key != NULL && find_key->no != key)
    {
        find_key = find_key->next;
        if (find_key != NULL)
            after_key = find_key->next;
    }

    if (find_key == NULL)
    {
        printf("\nkey tidak ditemukan\n");
        is_delete_key_found = 0;
    }
    else
    {
        if (after_key == NULL)
        {
            printf("Ini adalah node terakhir, tidak bisa delete after\n");
            return;
        }
        else
        {
            if (after_key->next == NULL)
            {
                find_key->next = NULL;
                is_delete_after_end = 1;
            }
            else
                find_key->next = after_key->next;

            free_node(after_key);
        }
    }
}