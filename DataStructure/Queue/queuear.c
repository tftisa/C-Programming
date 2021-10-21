#include <stdio.h>
#include <stdlib.h>
#include "queuear.h"
#include "fatal.h"

#define MINQUEUESIZE (5)

struct QueueRecord {
    int Capacity;
    int Front;
    int Rear;
    int Size;
    ElementType *Array;
};

int main(void) {
    Queue Q;
    
    Q = CreateQueue(12);

    for (int i = 0; i < 10; ++i) {
        Enqueue(i, Q);
    }

    while (!IsEmpty(Q)) {
        printf("%d\n", Front(Q));
        Dequeue(Q);
    }

    for (int i = 0; i < 10; ++i) {
        Enqueue(i, Q);
    }

    while (!IsEmpty(Q)) {
        printf("%d\n", Front(Q));
        Dequeue(Q);
    }

    DisposeQueue(Q);
    return 0;
}

int IsEmpty(Queue Q) {
    return Q->Size == 0;
}

int IsFull(Queue Q) {
    return Q->Size == Q->Capacity;
}

void MakeEmpty(Queue Q) {
    Q->Size = 0;
    Q->Front = 1;
    Q->Rear = 0;
}

Queue CreateQueue(int MaxElements) {
    Queue Q;

    if (MaxElements < MINQUEUESIZE) {
        Error("Queue size is too small");
    }

    Q = (Queue)malloc(sizeof(struct QueueRecord));

    if (Q == NULL) {
        Error("Out of space");
    }

    Q->Array = (ElementType *)malloc(sizeof(ElementType) * MaxElements);
    if (Q->Array == NULL) {
        FatalError("Out of space");
    }
    Q->Capacity = MaxElements;
    MakeEmpty(Q);

    return Q;
}

static int Succ(int Value, Queue Q) {
    if (++Value == Q->Capacity)
        Value = 0;
    return Value;
}

void DisposeQueue(Queue Q) {
    if (Q != NULL) {
        free(Q->Array);
        free(Q);
    }
}

ElementType Front(Queue Q) {
    if (!IsEmpty(Q)) {
        return Q->Array[Q->Front];
    }

    Error("Empty queue");
    return 0;
}

void Dequeue(Queue Q) {
    if (!IsEmpty(Q)) {
        Q->Size--;
        Q->Front = Succ(Q->Front, Q); 
    } else {
        Error("Empty queue");
    }
}

void Enqueue(ElementType X, Queue Q) {
    if (IsFull(Q)) {
        Error("Full Queue");
    } else {
        Q->Size++;
        Q->Rear = Succ(Q->Rear, Q);
        Q->Array[Q->Rear] = X;
    }
}