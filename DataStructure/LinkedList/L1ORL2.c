#include <stdio.h>
#include <stdbool.h>
#include "fatal.h"

struct Node;
typedef struct Node *PtrToNode;
typedef PtrToNode List;
typedef int ElementType;

List OR(List L1, List L2);
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

    List L = OR(L1, L2);

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

List OR(List L1, List L2) {
    PtrToNode p1, p2, tmp, rear;
    List L;

    p1 = L1;
    p2 = L2;

    if (!L1)    return L2;
    if (!L2)    return L1;

    L = (List)malloc(sizeof(struct Node));
    if (L == NULL) {
        Error("Out of space");
    }
    L->next = NULL;
    rear = L;

    while (p1 && p2) {
        switch(Compare(p1->data, p2->data)) {
            case 1:
                attach(p2->data, &rear);
                p2 = p2->next;
            
            case 0:
                attach(p1->data, &rear);
                p1 = p1->next;
                p2 = p2->next;
            
            case -1:
                attach(p1->data, &rear);
                p1 = p1->next;
        }
    }

    while (p1) {
        attach(p1->data, &rear);
        p1 = p1->next;
    }

    while (p2) {
        attach(p2->data, &rear);
        p2 = p2->next;
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
    if (p == NULL) 
        Error("Out of space");
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