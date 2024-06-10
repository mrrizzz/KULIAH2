#include <stdio.h>
#include <stdlib.h>
#include <ctype.h>

typedef struct Node {
    char value;
    struct Node* left;
    struct Node* right;
} Node;

typedef struct StackNode {
    Node* treeNode;
    struct StackNode* next;
} StackNode;

typedef struct CharStackNode {
    char operator;
    struct CharStackNode* next;
} CharStackNode;

Node* createNode(char value);
void push(StackNode** top, Node* treeNode);
Node* pop(StackNode** top);
void pushChar(CharStackNode** top, char operator);
char popChar(CharStackNode** top);
Node* constructTree(char* expression);
void preorder(Node* node);
void inorder(Node* node);
void postorder(Node* node);

int main() {
    char expression[10];
    printf("MEMBENTUK TREE DARI SEBUAH EKSPRESI ARITMATIKA\nDENGAN MEMANFAATKAN STRUKTUR DATA STACK\n\n");
    printf("Masukkan ekspresi dalam notasi infix : ");
    scanf("%99s", expression); 

    Node* root = constructTree(expression);

    printf("Hasil kunjungan secara hasiPreorder traversal:\n");
    preorder(root);
    printf("\nHasil kunjungan secara Inorder traversal:\n");
    inorder(root);
    printf("\nHasil kunjungan secara Postorder traversal:\n");
    postorder(root);
    printf("\n");

    return 0;
}

// Fungsi untuk membuat node pohon biner baru
Node* createNode(char value) {
    Node* newNode = (Node*)malloc(sizeof(Node));
    newNode->value = value;
    newNode->left = NULL;
    newNode->right = NULL;
    return newNode;
}

void push(StackNode** top, Node* treeNode) {
    StackNode* newStackNode = (StackNode*)malloc(sizeof(StackNode));
    newStackNode->treeNode = treeNode;
    newStackNode->next = *top;
    *top = newStackNode;
}

Node* pop(StackNode** top) {
    if (*top == NULL) {
        return NULL;
    }
    StackNode* temp = *top;
    *top = (*top)->next;
    Node* treeNode = temp->treeNode;
    free(temp);
    return treeNode;
}

void pushChar(CharStackNode** top, char operator) {
    CharStackNode* newStackNode = (CharStackNode*)malloc(sizeof(CharStackNode));
    newStackNode->operator = operator;
    newStackNode->next = *top;
    *top = newStackNode;
}

char popChar(CharStackNode** top) {
    if (*top == NULL) {
        return '\0';
    }
    CharStackNode* temp = *top;
    *top = (*top)->next;
    char operator = temp->operator;
    free(temp);
    return operator;
}

Node* constructTree(char* expression) {
    StackNode* stOperan = NULL;
    CharStackNode* stOperator = NULL;

    for (int i = 0; expression[i] != '\0'; i++) {
        if (expression[i] == '(') {
            pushChar(&stOperator, expression[i]);
        } else if (isdigit(expression[i])) {
            push(&stOperan, createNode(expression[i]));
        } else if (expression[i] == '+' || expression[i] == '-' || expression[i] == '*' || expression[i] == '/') {
            pushChar(&stOperator, expression[i]);
        } else if (expression[i] == ')') {
            while (stOperator != NULL && stOperator->operator != '(') {
                char operator = popChar(&stOperator);
                Node* right = pop(&stOperan);
                Node* left = pop(&stOperan);
                Node* node = createNode(operator);
                node->right = right;
                node->left = left;
                push(&stOperan, node);
            }
            popChar(&stOperator); 
        }
    }

    while (stOperator != NULL) {
        char operator = popChar(&stOperator);
        Node* right = pop(&stOperan);
        Node* left = pop(&stOperan);
        Node* node = createNode(operator);
        node->right = right;
        node->left = left;
        push(&stOperan, node);
    }

    return pop(&stOperan);
}

void preorder(Node* node) {
    if (node != NULL) {
        printf("%c ", node->value);
        preorder(node->left);
        preorder(node->right);
    }
}

// Fungsi traversal inorder
void inorder(Node* node) {
    if (node != NULL) {
        inorder(node->left);
        printf("%c ", node->value);
        inorder(node->right);
    }
}

void postorder(Node* node) {
    if (node != NULL) {
        postorder(node->left);
        postorder(node->right);
        printf("%c ", node->value);
    }
}
