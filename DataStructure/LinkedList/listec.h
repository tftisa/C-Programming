#include <stdlib.h>
#include <stdbool.h>
#include "fatal.h"

struct Node;
typedef struct Node *PtrToNode;
typedef PtrToNode Position;
typedef PtrToNode List;
typedef int ElementType;

bool isEmpty(List L);
void insert(List L, ElementType X, Position P);
void insertLastPosition(List L, ElementType X);
void deleteNode(List L, ElementType X);
PtrToNode find(List L, ElementType X);
void disposeList(List L);

struct Node {
    ElementType data;
    PtrToNode next;
};

bool isEmpty(List L) {
    return L->next == NULL;
}

void insert(List L, ElementType X, Position P) {
    PtrToNode p = (PtrToNode)malloc(sizeof(struct Node));
    p->data = X;

    p->next = P->next;
    P->next = p;
}

void insertLastPosition(List L, ElementType X) {
    PtrToNode p, tmp;
    p = L;
    while (p->next) {
        p = p->next;
    }

    tmp = (PtrToNode)malloc(sizeof(struct Node));
    if (tmp == NULL)
        Error("Out of space");
    tmp->data = X;
    tmp->next = NULL;
    p->next = tmp;
}

void deleteNode(List L, ElementType X) {
    PtrToNode p, tmp;

    p = L;
    while (p->next && p->next->data != X) {
        p = p->next;
    }

    if (p->next == NULL)
        Error("Failed to delete");
    
    tmp = p->next;
    p->next = p->next->next;
    free(tmp);
}

PtrToNode find(List L, ElementType X) {
    PtrToNode p;
    
    p = L;
    while (p->next && p->next->data != X) {
        p = p->next;
    }

    if (p->next == NULL) {
        Error("Failed to find");
    }

    return p->next;
}

void disposeList(List L) {
    PtrToNode tmp;
    while (L) {
        tmp = L;
        L = L->next;
        free(L);
    }
}