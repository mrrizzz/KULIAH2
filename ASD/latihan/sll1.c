#include <stdlib.h>
#include <stdio.h>

typedef struct Node
{
    int data;
    struct Node *next;
} Node;

void alokasi();
void sisipkanDiawal();
void sisipkanDiakhir();
void after(int);
void before(int);
void tampil();
void free_memory();

Node *head = NULL, *tail = NULL, *current = NULL;
int main(int argc, char const *argv[])
{
    int keyAfter = 0, keyBefore;
    char choice;
    int i = 1;
    do
    {
        printf("Insert data - %d : \n", i);
        alokasi();
        // sisipkanDiakhir();
        if (head != NULL)
        {
            // printf("Insert after : ");
            // scanf("%d", &keyAfter);
            printf("Insert before : ");
            scanf("%d", &keyBefore);

            getchar();
        }
        // after(keyAfter);
        before(keyBefore);
        printf("again ? ");
        choice = getchar();
        i++;
    } while (choice == 'y' || choice == 'Y');
    tampil();
    free_memory();
    return 0;
}

void alokasi()
{
    current = (Node *)malloc(sizeof(Node));
    if (current == NULL)
    {
        printf("failed allocation\n");
        exit(1);
    }
    printf("Contain : ");
    scanf("%d", &current->data);
    current->next = NULL;
    getchar();
}

void sisipkanDiawal()
{
    if (head != NULL)
    {
        current->next = head;
    }
    head = current;
}

void sisipkanDiakhir()
{
    if (head == NULL)
    {
        head = current;
        tail = current;
    }
    else
    {
        tail->next = current;
        tail = current;
    }
}

void after(int key)
{
    Node *findKey;
    if (head == NULL)
    {
        head = current;
    }
    else
    {
        findKey = head;
        while (findKey->data != key)
        {
            if (findKey->next == NULL)
                printf("GAGAL MENEMUKAN KEY\n");
            findKey = findKey->next;
        }
        current->next = findKey->next;
        findKey->next = current;
    }
}
void before(int key)
{
    Node *findKey, *prev = NULL;
    if (head == NULL)
    {
        head = current;
    }
    else
    {
        findKey = head;
        prev = NULL;   
        while (findKey->data != key)
        {
            prev = findKey;
            if (findKey->next == NULL)
                printf("GAGAL MENEMUKAN KEY\n");
            findKey = findKey->next;
        }
        if (prev == NULL)
        {
            current->next = head; //coba pakai findkey
            head = current;  
        }else{
            current->next = prev->next;
            prev->next = current;
        }
    }
}
void tampil()
{
    Node *baca = head;
    while (baca != NULL)
    {
        printf("angka %d\n", baca->data);
        baca = baca->next;
    }
}

void free_memory()
{
    Node *temp;
    while (head != NULL)
    {
        temp = head;
        head = head->next;
        free(temp);
    }
}
