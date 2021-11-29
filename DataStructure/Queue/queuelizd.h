#include <stdlib.h>
#include <stdbool.h>
#include "fatal.h"

struct Node;
struct QNode;
typedef struct Node *PtrToNode;
typedef PtrToNode Position;
typedef struct QNode *Queue; 
typedef int ElementType;

bool IsEmpty(Queue Q);
Queue CreateQueue();
void Enqueue(Queue Q, ElementType X);
ElementType Dequeue(Queue Q);
void DisposeQueue(Queue Q);

struct Node {
    ElementType Data;
    PtrToNode Next;
};

struct QNode {
    PtrToNode Front;
    PtrToNode Rear;
};

bool IsEmpty(Queue Q) {
    return Q->Front == NULL;
}

Queue CreateQueue() {
    Queue Q;

    Q = (Queue)malloc(sizeof(struct QNode));
    if (Q == NULL) {
        Error("Out of space");
    }
    Q->Front = Q->Rear = NULL;

    return Q;
}

void Enqueue(Queue Q, ElementType X) {
    PtrToNode p;

    p = (PtrToNode)malloc(sizeof(struct Node));
    if (p == NULL) {
        Error("Out of space");
    }
    p->Data = X;
    p->Next = NULL;

    if (Q->Front == NULL) {
        Q->Front = Q->Rear = p;
    } else {
        Q->Rear->Next = p;
        Q->Rear = p;
    }
}

ElementType Dequeue(Queue Q) {
    if (IsEmpty(Q)) {
        Error("Empty queue");
    }
    
    PtrToNode Tmp = Q->Front;
    int FrontElem = Tmp->Data;

    if (Q->Front == Q->Rear) {
        Q->Front = Q->Rear = NULL;
    } else {
        Q->Front = Q->Front->Next;
    }

    free(Tmp);
    return FrontElem;

}

void DisposeQueue(Queue Q) {
    if (Q) {
        PtrToNode p;

        while (Q->Front) {
            p = Q->Front;
            Q->Front = Q->Front->Next;
            free(p);    
        }
    }
}