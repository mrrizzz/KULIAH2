#include "../head.h"

void menu_insert()
{
    int exit = 0;
    int insert_choice;

    failed_in_after = 0;
    failed_in_before = 0;
    printf("Menu Insert\n1. AWAL\n2. AKHIR\n3. AFTER\n4. BEFORE\n0. exit\n");
    printf("Masukkan pilihan : ");
    scanf("%d", &insert_choice);
    switch (insert_choice)
    {
    case 1:
        insert_awal();
        break;
    case 2:
        insert_akhir();
        break;
    case 3:
        (head != NULL) ? insert_after() : (clearScreen(), printf("SLL Masih kosong, tidak bisa insert after\n"));
        printf(failed_in_after == 1 ? "key tidak ditemukan\n" : "");
        break;
    case 4:
        (head != NULL) ? insert_before() : (clearScreen(), printf("SLL Masih kosong, tidak bisa insert before\n"));
        printf(failed_in_before == 1 ? "key tidak ditemukan\n" : "");
        break;
    case 0:
        return;
        break;
    default:
        clearScreen();
        printf("Pilihan anda tadi tidak valid, silahkan coba lagi\n");
        break;
    }
}
