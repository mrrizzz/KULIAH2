#include <stdio.h>
#include <stdlib.h>

// Struktur node dalam linked list
struct Node {
    int data;
    struct Node* next;
};

// Fungsi untuk membuat node baru
struct Node* newNode(int data) {
    struct Node* node = (struct Node*)malloc(sizeof(struct Node));
    node->data = data;
    node->next = NULL;
    return node;
}

// Fungsi untuk menambahkan node baru di awal linked list
void prepend(struct Node** head, int data) {
    struct Node* newNode = (struct Node*)malloc(sizeof(struct Node));
    newNode->data = data;
    newNode->next = *head;
    *head = newNode;
}

// Fungsi untuk menghapus node setelah kunci tertentu
void deleteNodeAfterKey(struct Node* head, int key) {
    struct Node* temp = head;
    while (temp != NULL && temp->data != key) {
        temp = temp->next;
    }
    if (temp == NULL || temp->next == NULL) {
        printf("Kunci tidak ditemukan atau kunci adalah node terakhir.\n");
        return;
    }
    struct Node* toDelete = temp->next;
    temp->next = temp->next->next;
    free(toDelete);
}

// Fungsi untuk menampilkan isi linked list
void printList(struct Node* node) {
    while (node != NULL) {
        printf("%d -> ", node->data);
        node = node->next;
    }
    printf("NULL\n");
}

int main() {
    struct Node* head = NULL;
    prepend(&head, 5);
    prepend(&head, 4);
    prepend(&head, 3);
    prepend(&head, 2);
    prepend(&head, 1);

    printf("Linked list awal: ");
    printList(head);

    int key = 3; // Kunci di sini adalah 3, kita ingin menghapus node setelah kunci ini.

    deleteNodeAfterKey(head, key);

    printf("Linked list setelah menghapus node setelah kunci %d: ", key);
    printList(head);

    return 0;
}
