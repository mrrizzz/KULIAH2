#include "../head.h"
void insert_before()
{
    node *findKey, *prev;

    prev = NULL;
    findKey = head;
    int key;

    alokasi();
    printf("Masukkan sebelum nilai ? ");
    scanf("%d", &key);

    while (findKey != NULL && findKey->data != key)
    {
        prev = findKey;
        findKey = findKey->next;
    }
    if (findKey == NULL){
        printf("Gagal menemukan key\n");
        failed_in_before = 1;
    }
    else
    {
        if (prev == NULL)
        {
            current->next = head;
            head = current;
        }
        else
        {
            current->next = prev->next;
            prev->next = current;
        }
    }
    // clearScreen();
}