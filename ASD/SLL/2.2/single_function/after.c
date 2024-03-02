#include "../head.h"

void after()
{
    // akhir();

    Siswa *findKey;
    int key;

    alokasi();
    findKey = head;
    printf("Masukkan setelah nilai ? ");
    scanf("%d", &key);
    while (findKey->next != NULL && findKey->nomor != key)
    {
        findKey = findKey->next;
    }
    if (findKey == NULL)
    {
        printf("Gagal menemukan key\n");
    }
    else
    {

        current->next = findKey->next;
        findKey->next = current;
    }
    // clearScreen();
    // tampil();
}
