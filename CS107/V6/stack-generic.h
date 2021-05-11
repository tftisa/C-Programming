#include<stdio.h>
#include<stdlib.h>
#include<string.h>
#include<stdbool.h>
#include<assert.h>

#define kInitialAllocationSize 4

typedef struct{
    void *elems;
    int elemSize;
    int logLength;
    int allocLength;
}stack;

void StackNew(stack *s, int elemSize);
void StackDispose(stack *s);
bool StackEmpty(stack *s);
void StackPush(stack *s, void *elemAddr);
void StackPop(stack *s, void *elemAddr);
static void StackGrow(stack *s);

void StackNew(stack *s, int elemSize){
    assert(elemSize > 0);
    s->elemSize = elemSize;
    s->logLength = 0;
    s->allocLength = kInitialAllocationSize;
    s->elems = malloc(kInitialAllocationSize * s->elemSize);
    assert(s->elems != NULL);
}

void StackDispose(stack *s){
    free(s->elems);
}

bool StackEmpty(stack *s){
    return s->logLength == 0;
}

void StackPush(stack *s, void *elemAddr){
    if(s->logLength == s->allocLength){
        StackGrow(s);
    }

    void *destAddr = (char *)s->elems + s->elemSize * s->logLength;
    memcpy(destAddr, elemAddr, s->elemSize);
    s->logLength++;
}

void StackPop(stack *s, void *elemAddr){
    assert(s->logLength > 0);

    void *source = (char *)s->elems + s->elemSize * (s->logLength - 1);
    memcpy(elemAddr, source, s->elemSize);

    s->logLength--;
}


static void StackGrow(stack *s){
    s->allocLength *= 2;
    s->elems = realloc(s->elems, s->allocLength * s->elemSize);
    assert(s->elems != NULL);
}