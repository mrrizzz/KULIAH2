#include "../head.h"
// comment out the unused part
void before()
{
    Siswa *findKey, *prev;

    prev = NULL;
    findKey = head;

    int key;
    alokasi();
    printf("Masukkan sebelum nilai ? ");
    scanf("%d", &key);

    while (findKey != NULL && findKey->nomor != key)
    {
        prev = findKey;
        findKey = findKey->next;
    }
    if (findKey == NULL){
        printf("Gagal menemukan key\n");
        failedInBefore = 1;
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
    clearScreen();
}