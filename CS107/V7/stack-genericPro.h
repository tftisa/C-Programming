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
    void (*freefn)(void*); 
}stack;

void StackNew(stack *s, int elemSize, void (*freefn)(void*));
void StackDispose(stack *s);
bool StackEmpty(stack *s);
void StackPush(stack *s, void *elemAddr);
void StackPop(stack *s, void *elemAddr);
static void StackGrow(stack *s);

void StackNew(stack *s, int elemSize, void (*freefn)(void*)){
    assert(elemSize > 0);
    s->elemSize = elemSize;
    s->logLength = 0;
    s->allocLength = kInitialAllocationSize;
    s->elems = malloc(kInitialAllocationSize * s->elemSize);
    s->freefn = freefn;
    assert(s->elems != NULL);
}

void StackDispose(stack *s){
    for(int i = 0; i < s->logLength; i++){
        /*
        如果s->elem中存放的的是char *,那么必须先将char *所指向的字符串释放掉，也就是使用s->freefn释放掉字符串的内存
        再讲char*所占的内存释放掉，也就是最后的free操作
        */
        s->freefn((char *)s->elems + i * s->elemSize);
    }
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

