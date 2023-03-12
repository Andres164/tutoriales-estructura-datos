#include <stdio.h>
#include <stdbool.h>
#define MAXSIZE 10000

// 1 typedef Stack
typedef struct
{
    int top;
    int length;
    int container[MAXSIZE];
} Stack;

// 2 new_Stack
void new_Stack(Stack* this)
{
    this->top = -1;
    this->length = 0;
}

// 3 isFull
bool isFull(Stack* this)
{
    if(this->length >= MAXSIZE)
        return true;
    return false;
}

// 4 push
void push(Stack* this, int newElement)
{
    if(isFull(this))
        return;
    this->top++;
    this->length++;
    this->container[this->top] = newElement;
}

// 5 isEmpty
bool isEmpty(Stack* this)
{
    if(this->length < 1)
        return true;
    return false;
}

// 6 pop
int pop(Stack* this)
{
    if(isEmpty(this))
        return -1;
    int popedElement = this->container[this->top];
    this->top--;
    this->length--;
    return popedElement;
}

// 6 emptyStack
void emptyStack(Stack* this)
{
    int numElements = this->length;
    for(int i = 1; i <= numElements; i++)
    {
        int indexActual = this->top;
        printf("Stack[%i] = %i\n", indexActual, pop(this));
    }
}


// 8 topElement
int topElement(Stack* this)
{
    if(isEmpty(this))
        return -1;
    return this->container[this->top];
}



