#include <stdio.h>
#include <stdlib.h>
#include <stdbool.h>

#define MAXDATA 100
typedef int ElementType;

typedef struct HeapStruct *MaxHeap;
struct HeapStruct {
    ElementType *Elements;
    int Size;
    int Capacity;
};

bool IsFull(MaxHeap H);
bool IsEmpty(MaxHeap H);
MaxHeap Create(int MaxSize);
void Insert(MaxHeap H, ElementType item);
ElementType DeleteMax(MaxHeap H);
void PercDown(MaxHeap H, int p);
void BuildHeap(MaxHeap H);

int main() {
    MaxHeap H = Create(10);
    
    for (int i = 1; i < 11; ++i) {
        H->Elements[i] = i;
    }

    H->Size = 10;

    BuildHeap(H);

    for (int i = 0; i < 10; ++i) {
        printf("%d \n", DeleteMax(H));
    }

    return 0;
}

bool IsEmpty(MaxHeap H) {
    return H->Size == 0;
}

bool IsFull(MaxHeap H) {
    return H->Size == H->Capacity;
}

MaxHeap Create(int MaxSize) {
    MaxHeap H = (MaxHeap)malloc(sizeof(struct HeapStruct));
    H->Elements = (ElementType *)malloc(sizeof(ElementType) * (MaxSize + 1));
    H->Size = 0;
    H->Capacity = MaxSize;
    H->Elements[0] = MAXDATA;

    return H;
}

void Insert(MaxHeap H, ElementType item) {
    if (IsFull(H)) {
        printf("Heap is full");
        return;
    }

    int i = ++H->Size;
    for (; H->Elements[i / 2] < item && i > 1; i /= 2) {
        H->Elements[i] = H->Elements[i / 2];
    }

    H->Elements[i] = item;
}

ElementType DeleteMax(MaxHeap H) {
    if (IsEmpty(H)) {
        printf("Heap is empty");
        exit(EXIT_FAILURE);
    }
    
    int Parent, Child;
    ElementType MaxItem = H->Elements[1];
    int temp = H->Elements[H->Size--];

    for (Parent = 1; Parent * 2 <= H->Size; Parent = Child) {
        Child = Parent * 2;
        if ((Child * 2 != H->Size) 
            && (H->Elements[Child + 1] > H->Elements[Child])) {
            ++Child;
        }

        if (temp > H->Elements[Child]) {
            break;
        } else {
            H->Elements[Parent] = H->Elements[Child];
        }
    }

    H->Elements[Parent] = temp;
    return MaxItem;
}

void PercDown(MaxHeap H, int p) {
    int Parent, Child;
    ElementType X;

    X = H->Elements[p];
    for (Parent = p; Parent * 2 <= H->Size; Parent = Child) {
        Child = Parent * 2;
        if ((Child != H->Size) && (H->Elements[Child] < H->Elements[Child + 1])) {
            ++Child;
        }

        if (X >= H->Elements[Child]) {
            break;
        } else {
            H->Elements[Parent] = H->Elements[Child];
        }
    }

    H->Elements[Parent] = X;
}

void BuildHeap(MaxHeap H) {
    for (int i = H->Size / 2; i > 0; --i) {
        PercDown(H, i);
    }
}