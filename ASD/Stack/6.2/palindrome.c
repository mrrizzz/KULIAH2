#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#define MAX 100

struct stack
{
  int content[MAX];
  int counter;
};
typedef struct stack stack;

void init(stack *);
void push(char, stack *);
char pop(stack *);
int isFull(stack);
int isEmpty(stack);
void isPalindrome();

int main(int argc, char const *argv[])
{
  isPalindrome();
  return 0;
}

void isPalindrome()
{
  stack palindrome;
  char words[50];
  char choice;
  int count_words;
  int index;
  int checker;
  do
  {
    init(&palindrome);
    printf("MENGECEK PALINDROM \nMasukkan kata yang ingin dicek : ");
    fgets(words, sizeof(words), stdin);
    words[strcspn(words, "\n")] = '\0';
    count_words = strlen(words);
    for (int i = 0; i < count_words; i++)
    {
      push(words[i], &palindrome);
    }
    index = 0;
    while (words[index] != '\0')
    {
      checker = (pop(&palindrome) == words[index]) ? 1 : 0;
      if (checker == 0)
        break;

      index++;
    }
    printf("%s %s PALINDROM\n\n", words, checker == 1 ? "adalah" : "bukan");
    printf("Mau coba lagi ? (y/t) ");
    scanf(&choice);
  } while (choice == 'y' || choice == 'Y');
}

void init(stack *s)
{
  s->counter = 0;
}
int isFull(stack check)
{
  return check.counter >= MAX;
}
int isEmpty(stack check)
{
  return check.counter == 0;
}

void push(char content, stack *toPush)
{
  if (isFull(*toPush))
  {
    printf("Stack is full\n");
    return;
  }
  else
  {
    toPush->content[toPush->counter] = content;
    toPush->counter++;
  }
}

char pop(stack *toPop)
{
  char temp;
  if (isEmpty(*toPop))
  {
    printf("Stack is empty\n");
    return '\0';
  }
  else
  {
    temp = toPop->content[--(toPop->counter)];
    return temp;
  }
}
