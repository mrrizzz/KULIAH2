#include "head.h"
// comment out the unused part
int failedInBefore = 0;
void before()
{
    Node *findKey, *prev;

    prev = NULL;
    findKey = head;

    int key;
    printf("\nSLL - INSERT BEFORE\n");
    // BEGINNING OF SINGLE FUNCTION PURPOSES
    // akhir();
    // alokasi();
    // printf("Masukkan sebelum nilai ? ");
    // scanf("%d", &key);
    // getchar();

    // while (findKey != NULL && findKey->data != key)
    // {
    //     prev = findKey;
    //     findKey = findKey->next;
    // }
    // if (findKey == NULL)
    //     failedInBefore = 1;
    // else
    // {
    //     if (prev == NULL)
    //     {
    //         current->next = head;
    //         head = current;
    //     }
    //     else
    //     {
    //         current->next = prev->next;
    //         prev->next = current;
    //     }
    // }
    // tampil();
    // free_memory();
    // return;
    // END OF SINGLE FUNCTION PURPOSES

    // BEGINNING OF MULTI FUNCTION PURPOSES
     alokasi();
     printf("Masukkan sebelum nilai ? ");
     scanf("%d", &key);

    while (findKey != NULL && findKey->data != key)
    {
        prev = findKey;
        findKey = findKey->next;
    }
    if (findKey == NULL)
        failedInBefore = 1;
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
    // END OF MULTI FUNCTION PURPOSES
}