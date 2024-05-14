#include "../head.h"
// comment out the unused part
int failedInBefore = 0;
void before()
{
    Node *findKey, *prev;
    // Siswa *findKey, *prev;

    prev = NULL;
    findKey = head;

    int key;
    printf("\nSLL - INSERT BEFORE\n");

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
    clearScreen();
    // END OF MULTI FUNCTION PURPOSES
}