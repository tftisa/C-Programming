#include <stdio.h>
#include <stdlib.h>
#include "stackar.h"
#include "fatal.h"

#define EmptyTOS (-1)
#define MinStackSize (5)

struct StackRecord
{
    int Capacity;
    int TopOfStack;
    ElementType *Array;
};

int main() {
    Stack S;
    
    S = CreateStack(12);
    for (int i = 0; i < 10; ++i) {
        Push(i, S);
    }

    while (!IsEmpty(S)) {
        printf("%d\n", Top(S));
        Pop(S);
    }

    DisposeStack(S);
    return 0;
}

int IsEmpty(Stack S)
{
    return S->TopOfStack == EmptyTOS;
}

int IsFull(Stack S) {
    return (S->TopOfStack + 1) == S->Capacity;
}

void MakeEmpty(Stack S)
{
    S->TopOfStack = EmptyTOS;
}

Stack CreateStack(int MaxElements)
{
    Stack S;

    if (MaxElements < MinStackSize)
    {
        Error("Stack size is too small");
    }

    S = malloc(sizeof(struct StackRecord));
    if (S == NULL)
        FatalError("Out of Space!!!");

    S->Array = malloc(sizeof(ElementType) * MaxElements);
    if (S->Array == NULL)
        FatalError("Out of space!!!");
    S->Capacity = MaxElements;
    MakeEmpty(S);

    return S;
}

void DisposeStack(Stack S)
{
    if (S != NULL)
    {
        free(S->Array);
        free(S);
    }
}

ElementType Top(Stack S)
{
    if (!IsEmpty(S))
        return S->Array[S->TopOfStack];

    Error("Empty stack");
    return 0;
}

void Push(ElementType X, Stack S)
{
    if (IsFull(S))
        Error("Full stack");
    else
        S->Array[++S->TopOfStack] = X;
}

void Pop(Stack S)
{
    if (IsEmpty(S))
        Error("Empty stack");
    else
        S->TopOfStack--;
}

ElementType TopAndPop(Stack S)
{
    if (!IsEmpty(S))
    {
        return S->Array[S->TopOfStack--];
    }

    Error("Empty Stack");
    return 0;
}