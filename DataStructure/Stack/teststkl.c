#include <stdio.h>
#include <stdlib.h>
#include "Stackli.h"
#include "fatal.h"

struct Node
{
    ElementType Element;
    PtrToNode Next;
};

int IsEmpty(Stack S)
{
    return S->Next == NULL;
}

/*Create a empty stack*/
Stack CreateStack(void)
{
    Stack S;

    S = malloc(sizeof(struct Node));

    if (S == NULL)
    {
        FatalError("Out of space!!!");
    }

    S->Next = NULL;
    MakeEmpty(S);
    return S;
}

void MakeEmpty(Stack S)
{
    if (S == NULL)
        Error("Must use CreateStack first");
    else
        while (!IsEmpty(S))
            Pop(S);
}

void DisposeStack(Stack S)
{
    MakeEmpty(S);
    free(S);
}

void Push(ElementType X, Stack S)
{
    PtrToNode TmpCell;

    TmpCell = malloc(sizeof(struct Node));
    if (TmpCell == NULL)
        FatalError("Out of space!!!");
    else
    {
        TmpCell->Element = X;
        TmpCell->Next = S->Next;
        S->Next = TmpCell;
    }
}

ElementType Top(Stack S)
{
    if (!IsEmpty(S))
    {
        return S->Next->Element;
    }

    Error("Empty Stack!!!");
    return 0;
}

void Pop(Stack S)
{
    PtrToNode FirstCell;

    if (IsEmpty(S))
        Error("Empty stack");
    else
    {
        FirstCell = S->Next;
        S->Next = S->Next->Next;
        free(FirstCell);
    }
}

int main() {
    Stack S;
    int  i;

    S = CreateStack();
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