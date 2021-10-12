#include <stdbool.h>
#include <stdio.h>

#include "fatal.h"

struct Node;
typedef struct Node *PtrToNode;
typedef PtrToNode List;
typedef int ElementType;

List And(List L1, List L2);
List CreateList();
int Compare(ElementType element1, ElementType element2);
void attach(ElementType X, PtrToNode *pRear);
void printList(List L);
bool isExist(List L, ElementType X);

struct Node {
    ElementType data;
    PtrToNode next;
};

int main(void) {
    List L1 = CreateList();
    List L2 = CreateList();

    List L = And(L1, L2);

    printList(L);
    return 0;
}

List CreateList() {
    List L = (List)malloc(sizeof(struct Node));
    if (L == NULL) Error("Out of space");

    PtrToNode p, rear, tmp;
    rear = L;

    ElementType data;
    scanf("%d", &data);

    while (data != -1) {
        attach(data, &rear);

        scanf("%d", &data);
    }

    tmp = L;
    L = L->next;
    free(tmp);
    return L;
}

List And(List L1, List L2) {
    if (!L1 || !L2)
        return NULL;

    List L;
    PtrToNode p1, tmp, rear;

    p1 = L1;
    L = (List)malloc(sizeof(struct Node));
    if (L == NULL) {
        Error("Out of space");
    }
    L->next = NULL;
    rear = L;

    while (p1) {
        if (isExist(L2, p1->data)) {
            attach(p1->data, &rear);
        }

        p1 = p1->next;
    }

    tmp = L;
    L = L->next;
    free(tmp);
    return L;
}

int Compare(ElementType element1, ElementType element2) {
    if (element1 > element2)
        return 1;
    else if (element1 == element2)
        return 0;
    else
        return -1;
}

void attach(ElementType X, PtrToNode *pRear) {
    PtrToNode p;

    p = (PtrToNode)malloc(sizeof(struct Node));
    if (p == NULL) Error("Out of space");
    p->data = X;
    p->next = NULL;

    (*pRear)->next = p;
    *pRear = p;
}

void printList(List L) {
    PtrToNode p = L;

    while (p) {
        printf("%d\n", p->data);
        p = p->next;
    }
}

bool isExist(List L, ElementType X) {
    PtrToNode p = L;

    while (p) {
        if (p->data == X) {
            return true;
        }

        p = p->next;
    }

    return false;
}