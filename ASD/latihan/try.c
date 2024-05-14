#include <stdio.h>
#include <stdlib.h>
#include <string.h>

#define MAX 100

struct Stack {
    int top;
    char array[MAX];
};

struct Stack* createStack();
int kosong(struct Stack* stack);
char cek(struct Stack* stack);
char pop(struct Stack* stack);
void push(struct Stack* stack, char op);
int operan(char ch);
int prioritas(char ch);
int infixToPostfix(char* exp);

int main() {
    char exp[MAX];
    char lagi;
    do {
        printf("Masukkan ekspresi dalam notasi infix: ");
        scanf("%s", exp);
        infixToPostfix(exp);
        printf("Mau mencoba lagi (y/t)? ");
        scanf(" %c", &lagi);
    } while(lagi == 'y' || lagi == 'Y');
    return 0;
}

struct Stack* createStack() {
    struct Stack* stack = (struct Stack*) malloc(sizeof(struct Stack));
    if (!stack) 
        return NULL;
    stack->top = -1;
    return stack;
}

int kosong(struct Stack* stack) {
    return stack->top == -1 ;
}

char cek(struct Stack* stack) {
    return stack->array[stack->top];
}

char pop(struct Stack* stack) {
    if (!kosong(stack))
        return stack->array[stack->top--] ;
    return '$';
}

void push(struct Stack* stack, char op) {
    stack->array[++stack->top] = op;
}

int operan(char ch) {
    return (ch >= 'a' && ch <= 'z') || (ch >= 'A' && ch <= 'Z') || (ch >= '0' && ch <= '9');
}

int prioritas(char ch) {
    switch (ch) {
        case '+':
        case '-':
            return 1;
        case '*':
        case '/':
            return 2;
        case '^':
            return 3;
    }
    return -1;
}

int infixToPostfix(char* exp) {
    int i, k;
    struct Stack* stack = createStack();
    if(!stack)
        return -1 ;
    for (i = 0, k = -1; exp[i]; ++i) {
        if (operan(exp[i]))
            exp[++k] = exp[i];
        else if (exp[i] == '(')
            push(stack, exp[i]);
        else if (exp[i] == ')') {
            while (!kosong(stack) && cek(stack) != '(')
                exp[++k] = pop(stack);
            if (!kosong(stack) && cek(stack) != '(')
                return -1; 
            else
                pop(stack);
        } else {
            while (!kosong(stack) && prioritas(exp[i]) <= prioritas(cek(stack)))
                exp[++k] = pop(stack);
            push(stack, exp[i]);
        }
    }
    while (!kosong(stack))
        exp[++k] = pop(stack);
    exp[++k] = '\0';
    printf( "Ungkapan postfiksnya = %s\n", exp );
}