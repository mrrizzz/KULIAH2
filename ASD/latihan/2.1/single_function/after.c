#include "../head.h"
// comment out the unused part
int failedInAfter = 0;
void after()
{
    Node *findKey;
    printf("\nSLL - INSERT DI AFTER\n");

    // BEGINNING OF MULTI FUNCTION PURPOSES
    findKey = head;
    while (findKey != NULL && findKey->data <= findKey->data)
        findKey = findKey->next;

    if (findKey == NULL)
        failedInAfter = 1;
    else
    {
        current->next = findKey->next;
        findKey->next = current;
    }
    // clearScreen();
}