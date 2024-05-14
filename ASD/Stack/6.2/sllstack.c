#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#define MAX 100

struct simpul
{
    int data;
    struct simpul *next;
};
typedef struct simpul Node;

void init();
void push();
char pop();
int isFull();
int isEmpty();

int main(){
  
}


