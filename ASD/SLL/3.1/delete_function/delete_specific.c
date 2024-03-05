#include "../head.h"

void delete_specific()
{
    node *find_key, *before_key = NULL;
    int key;

    printf("Hapus nilai... ");
    scanf("%d", &key);
    if (head->next == NULL)
    {
        delete_awal();
    }
    else
    {

        find_key = head;
        while (find_key != NULL && find_key->data != key)
        {
            before_key = find_key;
            find_key = find_key->next;
        }
        if (find_key == NULL)
            printf("key tidak ditemukan\n\n");
        else
        {
            if (before_key == NULL)
                head = head->next;
            else
            {
                before_key->next = find_key->next;
            }
            free_node(find_key);
        }
    }
}