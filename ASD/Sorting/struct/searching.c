#include "header.h"

void sequential_search(int key, int search_by) {
  int found = 0;
  for (int i = 0; i < ARRAY_SIZE; i++) {
    if ((search_by == 1 && data_siswa[i].no == key) ||
        (search_by == 2 && strcmp(data_siswa[i].nama, (char *)key) == 0)) {
      printf("Data ditemukan di index %d: No: %d, Nama: %s, Nilai: %d\n", i,
             data_siswa[i].no, data_siswa[i].nama, data_siswa[i].nilai);
      found = 1;
    }
  }
  if (!found) {
    printf("");
  }
}

void binary_search(int key, int search_by) {
  quick_wrapper();
  int left = 0, right = ARRAY_SIZE - 1, mid;
  int found = 0;

  while (left <= right) {
    mid = (left + right) / 2;
    if ((search_by == 1 && data_siswa[mid].no == key) ||
        (search_by == 2 && strcmp(data_siswa[mid].nama, (char *)key) == 0)) {
      printf("Data ditemukan di index %d: No: %d, Nama: %s, Nilai: %d\n", mid,
             data_siswa[mid].no, data_siswa[mid].nama, data_siswa[mid].nilai);
      found = 1;
      break;
    } else if ((search_by == 1 && data_siswa[mid].no > key) ||
               (search_by == 2 &&
                strcmp(data_siswa[mid].nama, (char *)key) > 0)) {
      right = mid - 1;
    } else {
      left = mid + 1;
    }
  }

  if (!found) {
    printf("Data tidak ditemukan\n");
  }
}

void menu_searching() {
  int choice, key;
  char key_str[50];
  int search_by;

  printf("MENU SEARCHING:\n");
  printf("1. Sequential Search\n");
  printf("2. Binary Search\n");
  printf("3. Keluar\n");
  printf("Pilihan anda [1/2/3]: ");
  scanf("%d", &choice);

  if (choice == 3)
    exit(0);

  printf("PENCARIAN BERDASARKAN:\n");
  printf("1. No\n");
  printf("2. Nama\n");
  printf("Pilihan anda [1/2]: ");
  scanf("%d", &search_by);

  if (search_by == 1) {
    printf("Masukkan no mhs yang akan dicari: ");
    scanf("%d", &key);
  } else {
    printf("Masukkan nama mhs yang akan dicari: ");
    scanf("%s", key_str);
    key = (int)key_str;
  }

  if (choice == 1) {
    sequential_search(key, search_by);
  } else if (choice == 2) {
    binary_search(key, search_by);
  }
}
