#include <stdio.h>
#include <stdlib.h>

struct AvlNode;
typedef struct AvlNode *Position;
typedef struct AvlNode *AvlTree;
typedef int ElementType;

AvlTree MakeEmpty(AvlTree T);
Position Find(ElementType X, AvlTree T);
Position FindMin(AvlTree T);
Position FindMax(AvlTree T);
AvlTree Insert(ElementType X, AvlTree T);
AvlTree Delete(ElementType X, AvlTree T);
ElementType Retrieve(Position P);

struct AvlNode {
    ElementType Element;
    AvlTree Left;
    AvlTree Right;
    int Height;
};

int main() {

}

AvlTree MakeEmpty(AvlTree T) {
    if (T != NULL) {
        MakeEmpty(T->Left);
        MakeEmpty(T->Right);
        free(T);
    }

    return NULL;
}

Position Find(ElementType X, AvlTree T) {
    Position P = T;

    while (P) {
        if (X < P->Data) {
            P = P->Left;
        } else if (X > P->Data) {
            P = P->Right;
        } else {
            return P;
        }
    }

    return NULL;
}

Position FindMin(AvlTree T) {
    Position P = T;

    if (P) {
        while (P->Left) {
            P = P->Left;
        }
    }

    return T;
}

Position FindMax(AvlTree T) {
    Position P = T;

    if(P) {
        while (P->Right) {
            P = P->Right;
        }
    }

    return T;
}

static int Max(int Height1, int Height2) {
    return Height1 > Height2 ? Height1 : Height2;
}

AvlTree Insert(ElementType X, AvlTree T) {
    if (T == NULL) {
        T = (AvlTree)malloc(sizeof(struct AvlNode));
        if (T == NULL) {
            printf("Out of space!!!");
        } else {
            T->Element = X;
            T->Height = 0;
            T->Left = T->Right = NULL;
        }
    } else if (X < T->Element) {
        T->Left = Insert(X, T->Left);
        if (Height(T->Left) - Height(T->Right) == 2) {
            if (X < T->Left->Element) {
                T = SingleRotateWithLeft(T);
            } else {
                T = DoubleRotateWithLeft(T);
            }
        }
    } else if (X > T->Element) {
        T->Right = Insert(X, T->Right);
        if (Height(T->Right) - Height(T->Left) == 2) {
            if (X > T->Right->Element) {
                T = SingleRotateWithRight(T);
            } else {
                T = DoubleRotateWithRight(T);
            }
        }
    }

    T->Height = Max(Height(T->Left), Height(T->Right)) + 1;

    return T;
}

static Position SingleRotateWithLeft(Position K2) {
    Position K1;

    K1 = K2->Left;
    K2->Left = K1->Right;
    K1->Right = K2;

    K2->Height = Max(Height(K2->Left), Height(K2->Right)) + 1;
    K1->Height = Max(Height(K1->Left), Height(K1->Right)) + 1;

    return K1;
}

static Position SingleRotateWithRight(Position K2) {
    Position K1;

    K1 = K2->Right;
    K2->Right = K1->Left;
    K1->Left = K2;

    K2->Height = Max(Height(K2->Left), Height(K2->Right)) + 1;
    K1->Height = Max(Height(K1->Left), Heihgt(K1->Right)) + 1;

    return k1;
}

static Postion DoubleRotateWithLeft(Position K3) {
    K3->Left = SingleRotateWithRight(K3->Left);

    return SingleRotateWithLeft(K3);
}

static Position DoubleRotateWithRight(Position K3) {
    K1->Right = SingleRotateWithLeft(K1->Right);

    return SingleRotateWithRight(K3);
}

AvlTree Delete(ElementType X, AvlTree T) {
    Position Tmp;

    if (T == NULL) {
        printf("Item not Found!");
        exit(EXIT_FAILURE);
    } else if (x < T->Element) {
        T->Left = Delete(X, T->Left);

        if (Height(T->Right) - Height(T->Left) == 2) {
            if (Height(T->Right->Right) > Height(T->Right->Left)) {
                T = SingleRotateWithRight(T);
            } else {
                T = DoubleRotateWithRight(T);
            }
        }
    } else if (X > T->Element) {
        T->Right = Delete(X, T->Right);

        if (Height(T->Left) - Height(T->Right) == 2) {
            if (Height(T->Left->Left) > Height(T->Left->Right)) {
                T = SingleRotateWithLeft(T);
            } else {
                T = DoubleRotateWithLeft(T);
            }
        }
    } else {
        if (T->Left && T->Right) {
            Tmp = FindMin(T->Right);
            T->Element = Tmp->Element;
            T->Right = Delete((T->Element, T->Right));

            if (Height(T->Left) - Height(T->Right) == 2) {
                if (Height(T->Left->Left) > Height(T->Left->Right)) {
                    T = SingleRotateWithLeft(T);
                } else {
                    T = DoubleRotateWithLeft(T);
                }
            }
        } else {
            Tmp = T;
            T = T->Left ? T->Left : T->Right;
            free(Tmp);
        }
    }

    if (T != NULL) {
        T->Height = MAX(Height(T->Left), Height(T->Right)) + 1;
    }

    return T;
}

ElementType Retrieve(Position P);

static int Height(Position P) {
    if (P == NULL) {
        return -1;
    } else {
        return P->Height;
    }
}
