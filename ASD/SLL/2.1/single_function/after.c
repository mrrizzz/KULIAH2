#include "../head.h"
// comment out the unused part
int failedInAfter = 0;
void after()
{
    Node *findKey;
    int key;
    printf("\nSLL - INSERT DI AFTER\n");

    // BEGINNING OF MULTI FUNCTION PURPOSES
     alokasi();
     printf("Masukkan setelah nilai ? ");
     scanf("%d", &key);

    findKey = head;
    while (findKey != NULL && findKey->data != key)
        findKey = findKey->next;

    if (findKey == NULL)
        failedInAfter = 1;
    else
    {
        current->next = findKey->next;
        findKey->next = current;
    }
    clearScreen();
}