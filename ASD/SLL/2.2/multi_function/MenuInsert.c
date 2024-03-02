#include "../head.h"

void MenuInsert()
{
    int exit = 0;
    int insert_choice;
    while (!exit)
    {
        failedInAfter = 0;
        failedInBefore = 0;
        printf("1. AWAL\n2. AKHIR\n3. AFTER\n4. BEFORE\n0. exit\n");
        printf("Masukkan pilihan : ");
        scanf("%d", &insert_choice);
        switch (insert_choice)
        {
        case 1:
            awal();
            break;
        case 2:
            akhir();
            break;
        case 3:
            (head != NULL) ? after() : (clearScreen(), printf("SLL Masih kosong, tidak bisa insert after\n"));
            printf(failedInAfter == 1 ? "key tidak ditemukan\n" : "");
            break;
        case 4:
            (head != NULL) ? before() : (clearScreen(), printf("SLL Masih kosong, tidak bisa insert before\n"));
            printf(failedInBefore == 1 ? "key tidak ditemukan\n" : "");
            break;
        case 0:
            exit = 1;
            break;
        default:
            clearScreen();
            printf("Pilihan anda tadi tidak valid, silahkan coba lagi\n");
            break;
        }
        tampil();
    }
}
