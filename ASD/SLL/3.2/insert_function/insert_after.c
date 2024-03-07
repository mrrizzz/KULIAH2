#include "../head.h"

void insert_after()
{
    node *findKey;
    int key;
    alokasi();
    findKey = head;
    printf("Masukkan setelah nilai ? ");
    scanf("%d", &key);
    while (findKey != NULL && findKey->no != key)
    {
        findKey = findKey->next;
    }
    if (findKey == NULL)
    {
        printf("Gagal menemukan key\n");
        failed_in_after = 1;
    }
    else
    {
        current->next = findKey->next;
        findKey->next = current;
    }
    // clearScreen();
}
