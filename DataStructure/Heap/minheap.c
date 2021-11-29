#include <stdbool.h>
#include <stdio.h>
#include <stdlib.h>

#define MINDATA -10000
typedef int ElementType;

typedef struct HeapStruct *MinHeap;
struct HeapStruct {
    ElementType *Elements;
    int Size;
    int Capacity;
};

bool IsFull(MinHeap H);
bool IsEmpty(MinHeap H);
MinHeap Create(int MaxSize);
void Insert(MinHeap H, ElementType item);
ElementType DeleteMin(MinHeap H);
void PercDown(MinHeap H, int p);
void BuildHeap(MinHeap H);

int main() {
    MinHeap H = Create(10);

    for (int i = 1; i < 11; ++i) {
        H->Elements[i] = 11 - i;
    }

    H->Size = 10;
    
    BuildHeap(H);

    for (int i = 0; i < 10; ++i) {
        printf("%d\n", DeleteMin(H));
    }

    return 0;
}

bool IsFull(MinHeap H) {
    return H->Size == H->Capacity;
}

bool IsEmpty(MinHeap H) {
    return H->Size == 0;
}

MinHeap Create(int MaxSize) {
    MinHeap H = (MinHeap)malloc(sizeof(struct HeapStruct));
    H->Elements = (ElementType *)malloc((MaxSize + 1) * sizeof(ElementType));
    H->Elements[0] = MINDATA;
    H->Size = 0;
    H->Capacity = MaxSize;
}

void Insert(MinHeap H, ElementType item) {
    if (IsFull(H)) {
        printf("Heap is FULL!!!");
        return;
    }

    int i = ++H->Size;
    for (; H->Elements[i / 2] > item && i > 1; i /= 2) {
        H->Elements[i] = H->Elements[i / 2];
    }

    H->Elements[i] = item;
}

ElementType DeleteMin(MinHeap H) {
    if (IsEmpty(H)) {
        printf("Heap is EMPTY!!!");
        exit(EXIT_FAILURE);
    }

    ElementType minItem = H->Elements[1];
    int temp = H->Elements[H->Size--];

    int Parent, Child;
    for (Parent = 1; Parent * 2 <= H->Size; Parent = Child) {
        Child = Parent * 2;

        if ((Child != H->Size) && (H->Elements[Child] > H->Elements[Child + 1])) {
            ++Child;
        }

        if (temp < H->Elements[Child]) {
            break;
        } else {
            H->Elements[Parent] = H->Elements[Child];
        }
    }
    H->Elements[Parent] = temp;

    return minItem;
}

void PercDown(MinHeap H, int p) {
    ElementType X = H->Elements[p];

    int Parent, Child;
    for (Parent = p; Parent * 2 <= H->Size; Parent = Child) {
        Child = Parent * 2;
        if ((Child != H->Size) && (H->Elements[Child] > H->Elements[Child + 1])) {
            ++Child;
        }

        if (X < H->Elements[Child]) {
            break;
        } else {
            H->Elements[Parent] = H->Elements[Child];
        }
    }

    H->Elements[Parent] = X;
}

void BuildHeap(MinHeap H) {
    for (int i = H->Size / 2; i > 0; --i) {
        PercDown(H, i);
    }
}