#include <stdbool.h>
#include <stdlib.h>
#include "fatal.h"

struct QNode;
typedef struct QNode *Queue;
typedef int Position;
typedef int ElementType;

Queue CreateQueue(int MaxSize);
bool IsFull(Queue Q);
void AddQ(Queue Q, ElementType X);
bool IsEmpty(Queue Q);
ElementType DeleteQ(Queue Q);
void DisposeQueue(Queue Q);

struct QNode {
    ElementType *Data;
    Position Front, Rear;
    int MaxSize;
};

Queue CreateQueue(int MaxSize) {
    Queue Q = (Queue)malloc(sizeof(struct QNode));

    if (Q == NULL) {
        Error("Empty queue");
    }

    Q->Data = (ElementType *)malloc(sizeof(ElementType) * MaxSize);
    if (Q->Data == NULL) {
        Error("Out of space");
    }
    Q->Front = Q->Rear = 0;
    Q->MaxSize = MaxSize;
}

bool IsFull(Queue Q) {
    return (Q->Rear + 1) % Q->MaxSize == Q->Front;
}

void AddQ(Queue Q, ElementType X) {
    if (!IsFull(Q)) {
        Q->Rear = (Q->Rear + 1) % Q->MaxSize;
        Q->Data[Q->Rear] = X;
    } else {
        Error("Full Queue");
    }
}

bool IsEmpty(Queue Q) {
    return Q->Front == Q->Rear;
}

ElementType DeleteQ(Queue Q) {
    if (!IsEmpty(Q)) {
        Q->Front = (Q->Front + 1) % Q->MaxSize;
        return Q->Data[Q->Front];
    } else {
        Error("Empty queue!");
    }
}

void DisposeQueue(Queue Q) {
    if (Q != NULL) {
        free(Q->Data);
        free(Q);
    }
}