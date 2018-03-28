// C program for array implementation of stack
#include <stdio.h>
#include <stdlib.h>
#include <limits.h>
 
/******Creating a Stack using Push and Pop function ********/
struct Stack
{
    int top;
    int size;
    int* array;
}; 

struct Stack* createStack(int size)
{
    struct Stack* s1 = (struct Stack*) malloc(sizeof(struct Stack));
    s1->size = size;
    s1->top = -1;
    s1->array = (int*) malloc(s1->size * sizeof(int));
    return s1;
}
 

int isStackFull(struct Stack* s1)
{   return s1->top == s1->size - 1; }
 
int isStackEmpty(struct Stack* s1)
{   return s1->top == -1;  }
 

void push(struct Stack* s1, int data)
{
    if (isStackFull(s1)){
        printf("Stack if Full");
        return;
    }
    s1->array[++s1->top] = data;
    printf("%d Pushed Stack Data\n", data);
}
 

int pop(struct Stack* s1)
{
    if (isStackEmpty(s1)){
        printf("Stack if Empty. Please push the data before pop it.\n");
        return INT_MIN;
    }
    return s1->array[s1->top--];
}

int main()
{
    struct Stack* s1 = createStack(100);
 
    push(s1, 1);
    push(s1, 2);
    push(s1, 3);
    push(s1, 4);
    push(s1, 5);
 
    printf("%d popped data from stack\n", pop(s1));
    printf("%d popped data from stack\n", pop(s1));
    printf("%d popped data from stack\n", pop(s1));
    printf("%d popped data from stack\n", pop(s1));
    printf("%d popped data from stack\n", pop(s1));
    printf("%d popped data from stack\n", pop(s1));
 
    return 0;
}