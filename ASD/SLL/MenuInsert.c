#include "head.h"

int main(int argc, char const *argv[])
{
    int index = 0;
    int exit = 0;
    int insert_choice;
    while (!exit)
    {
        printf("1. AWAL\n2. AKHIR\n3. AFTER\n4. BEFORE\n0. exit\n");
        printf("Masukkan pilihan : ");
        scanf("%d", &insert_choice);
        switch (insert_choice)
        {
        case 1:
            awal();
            // clearScreen();
            break;
        case 2:
            akhir();
            // clearScreen();
            break;
        case 3:
            // comment out line 24 for multi function purpose
            // after();
            // comment out line 26 for single function purpose
            (head != NULL && index != 0) ? after() : printf("SLL Masih kosong, tidak bisa insert after\n");
            break;
        case 4:
            // comment out line 29 for multi function purpose
            // before();
            // comment out line 31 for single function purpose
            (head != NULL && index != 0) ? before() : printf("SLL Masih kosong, tidak bisa insert after\n");
            break;
        case 0:
            exit = 1;
            break;
        default:
            // clearScreen();
            printf("Pilihan anda tadi tidak valid, silahkan coba lagi\n");
            break;
        }
        tampil();
        index++;
    }
    free_memory();
    return 0;
}
