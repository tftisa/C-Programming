#include <stdio.h>
#include <stdlib.h>
#include <stdbool.h>
#include "fatal.h"

struct Node;
typedef struct Node *PtrToNode;
typedef PtrToNode Stack;
typedef char ElementType;

int IsEmpty(Stack S);
Stack StackCreate();
void Push(Stack S, ElementType element);
ElementType Top(Stack S);
void Pop(Stack S);
void MakeEmpty(Stack S);
void DisposeStack(Stack S);
bool BalanceSymbols(char *s);

struct Node {
    ElementType element;
    PtrToNode next;
};

int main(void) {
    char symbols[20];{}
    gets(symbols);

    if (BalanceSymbols(symbols)) {
        printf("Success!!");
    } else {
        printf("Failed!!!");
    }

    return 0;
}

int IsEmpty(Stack S) {
    return S->next == NULL;
}

Stack StackCreate() {
    Stack S = (Stack)malloc(sizeof(struct Node));

    if (S == NULL) 
        Error("Out of space!!!");
    
    S->next = NULL;
    return S;
}

void Push(Stack S, ElementType element) {
    PtrToNode p = (PtrToNode)malloc(sizeof(struct Node));
    if (p == NULL) {
        Error("Out of space!!!");
    }

    p->element = element;
    p->next = S->next;
    S->next = p;
}

ElementType Top(Stack S) {
    return S->next->element;
}

void Pop(Stack S) {
    PtrToNode Tmp;

    if (IsEmpty(S)) {
        Error("Empty stack");
    }

    Tmp = S->next;
    S->next = S->next->next;
    free(Tmp);
}

void MakeEmpty(Stack S) {
    if (S != NULL) {
        while (S->next) {
            Pop(S);
        }
    }
}

void DisposeStack(Stack S) {
    if (S != NULL) {
        MakeEmpty(S);
        free(S);
    }
}

bool BalanceSymbols(char *s) {
    Stack S = StackCreate();

    while (*s != '\0') {
        if (*s == '{' || *s == '(' || *s == '[') {
            Push(S, *s);
        } else {
            if (*s == '}' && Top(S) == '{') {
                Pop(S);
            } else if (*s == ')' && Top(S) == '(') {
                Pop(S);
            } else if (*s == ']' && Top(S) == '[') {
                Pop(S);
            } else if (*s == ' ') {
                *s++;
                continue;
            } else {
                return false;
            }
        }

        *s++;
    }

    if (!IsEmpty(S)) {
        return false;
    }

    return true;
}