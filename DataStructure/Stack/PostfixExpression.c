#include <stdio.h>
#include <stdlib.h>
#include "fatal.h"

struct Node;
typedef struct Node *PtrToNode;
typedef PtrToNode Stack;
typedef int ElementType;

int IsEmpty(Stack S);
Stack CreateStack();
void MakeEmpty(Stack S);
void Push(Stack S, ElementType element);
ElementType Pop(Stack S);
void DisposeStack(Stack S);
void ValueOfPostfixExpression(char *s);

struct Node {
    ElementType element;
    PtrToNode next;
};

int main(void) {
    char expression[30];
    gets(expression);

    ValueOfPostfixExpression(expression);

    return 0;
}

int IsEmpty(Stack S) {
    return S->next == NULL;
}

Stack CreateStack() {
    Stack S = (Stack)malloc(sizeof(struct Node));
    if (S == NULL) {
        Error("Out of space!!!");
    }
    S->next = NULL;

    return S;
}

void MakeEmpty(Stack S) {
    if (S != NULL) {
        while (S->next) {
            Pop(S);
        }
    }
}

void Push(Stack S, ElementType element) {
    PtrToNode Tmp = (PtrToNode)malloc(sizeof(struct Node));

    if (Tmp == NULL)
        Error("Out of space!!!");
    
    Tmp->element = element;
    Tmp->next = S->next;
    S->next = Tmp;
}

ElementType Pop(Stack S) {
    PtrToNode Tmp;
    ElementType value;

    if (IsEmpty(S)) {
        Error("Empty stack");
    }

    Tmp = S->next;
    value = Tmp->element;
    S->next = S->next->next;
    free(Tmp);

    return value;
}

void DisposeStack(Stack S) {
    if (S != NULL) {
        MakeEmpty(S);
        free(S);
    }
}

void ValueOfPostfixExpression(char *s) {
    Stack S = CreateStack();

    while (*s) {
        //when s point to a figure
        if (*s >= '0' && *s <= '9') {
            Push(S, (*s - '0'));        
        } else {
            int value = 1;
            int TopOfStackValue;
            int SecondTopOfStackValue;
            if (*s == '+') {
                TopOfStackValue = Pop(S);
                SecondTopOfStackValue = Pop(S);
                value = TopOfStackValue + SecondTopOfStackValue;
                Push(S, value);
            } else if (*s == '*') {
                TopOfStackValue = Pop(S);
                SecondTopOfStackValue = Pop(S);
                value = TopOfStackValue * SecondTopOfStackValue;
                Push(S, value);
            } else if (*s == '-') {
                TopOfStackValue = Pop(S);
                SecondTopOfStackValue = Pop(S);
                value = TopOfStackValue - SecondTopOfStackValue;
                Push(S, value);
            } else if (*s == '/') {
                TopOfStackValue = Pop(S);
                SecondTopOfStackValue = Pop(S);
                value = TopOfStackValue / SecondTopOfStackValue;
                Push(S, value);
            } else if(*s == ' ') {
                *s++;
                continue;
            } else {
                Error("unrecognizable symbol");
            }
        }

        *s++;
    }

    ElementType result = Pop(S);
    DisposeStack(S);

    printf("result = %d", result);
}
