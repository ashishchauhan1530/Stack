#include <stdio.h>
#include <stdlib.h>
#include <limits.h>

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
{   
    if(s1->top== -1){
        return 1;
    }else{
        return 0;
    }
}
 

void push(struct Stack* s1, int data)
{
    if (isStackFull(s1)){
        printf("Stack if Full");
        return;
    }
    s1->array[++s1->top] = data;
   // printf("%d Pushed Stack Data\n", data);
}
 

int pop(struct Stack* s1)
{
    if (isStackEmpty(s1)){
        printf("Stack if Empty. Please push the data before pop it.\n");
        return;
    }
    return s1->array[s1->top--];
}
void insertData(struct Stack* s1, int dataItem){
    if (isStackEmpty(s1)==1){        
        push(s1,dataItem);
        return;
    }
    int tempData = pop(s1);
    insertData(s1,dataItem);
    push(s1,tempData);
}

void reversedStack(struct Stack* s1){
    int reversedItem;
    if (isStackEmpty(s1)){        
        return;
    }
    reversedItem = pop(s1);
    reversedStack(s1);
    insertData(s1,reversedItem);
}

int main()
{
    
    printf("-In reversedStack Function , it does recursive function call until it becomes empty.\n");
    printf("-In inserData Function , take data one by one from stack of reversedStack and \n-I am inserting all the data in it.\n");
    printf("-In inserData Function , tempData holds all the data and tempData push the data \nafter inserting all the data from stack of reversedStack Funtion .\n\n\n\n\n");
    
    
    struct Stack* s1 = createStack(100);
 
    push(s1, 1);
    push(s1, 2);
    push(s1, 3);
    push(s1, 4);
    push(s1, 5);
 
    printf("Given Stack is \n");


    while(isStackEmpty(s1)!=1){
        int popedDataItem = pop(s1);
        printf("%d\n",popedDataItem);
    }
    
    push(s1, 1);
    push(s1, 2);
    push(s1, 3);
    push(s1, 4);
    push(s1, 5);
    
    reversedStack(s1);
    
    printf("Reverese Stack is \n");
    
    while(isStackEmpty(s1)!=1){
        int popedDataItem = pop(s1);
        printf("%d\n",popedDataItem);
    }
    
    return 0;
}