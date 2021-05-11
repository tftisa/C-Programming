#include<stdio.h>
#include<stdlib.h>
#include<assert.h>

typedef struct{
    int *elems;
    int logicalLength;  //Used, point to the top of stack
    int allocLength;
}stack;

void stackNew(stack *s);
void stackDispose(stack *s);
void stackPush(stack *s, int value);
int stackPop(stack *s);

void stackNew(stack *s){
    s->logicalLength = 0;
    s->allocLength = 4;
    s->elems = (int *)malloc(s->allocLength * sizeof(int));

    assert(s->elems == NULL);
    /*
    if the content in assert function is true, it does nothing
    if the content in assert function is false, it will end the program
    and tells you what line the program ended at, it tells you the file
    number containing and line number of the assert 
    */
}

void stackDispose(stack *s){
    free(s->elems);
}

void stackPush(stack *s, int value){
    //if stack is full
    if(s->logicalLength == s->allocLength){
        s->allocLength *= 2;
        s->elems = (int *)realloc(s->elems, s->allocLength);
        //if there is not enough memory to allocate, it will return null,
        // but it won't free the original block
        assert(s->elems != NULL);
    }
    s->elems[s->logicalLength++] = value;
}

int stackPop(stack *s){
    assert(s->logicalLength > 0);

    return s->elems[s->logicalLength--];
}