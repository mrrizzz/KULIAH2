#include "../head.h"

void after()
{
    Siswa *findKey;
    int key;

    alokasi();
    findKey = head;
    printf("Masukkan setelah nilai ? ");
    scanf("%d", &key);
    while (findKey != NULL && findKey->nomor != key)
    {
        findKey = findKey->next;
    }
    if (findKey == NULL)
    {
        printf("Gagal menemukan key\n");
        failedInAfter = 1;
    }
    else
    {
        current->next = findKey->next;
        findKey->next = current;
    }
    clearScreen();
}
