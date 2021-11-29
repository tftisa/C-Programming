#include <stdio.h>
#include <stdlib.h>

struct TreeNode;
typedef struct TreeNode *PtrToNode;
typedef PtrToNode BinTree;
typedef int ElementType;

struct TreeNode {
    int Data;
    PtrToNode Left;
    PtrToNode Right;
};

PtrToNode NewNode(int Data);
PtrToNode Find(ElementType X, BinTree BST);
PtrToNode FindMin(BinTree BST);
PtrToNode FindMax(BinTree BST);
PtrToNode Insert(ElementType X, BinTree BST);
PtrToNode Delete(ElementType X, BinTree BST);

int main() {
    BinTree BST = NewNode(10);
    Insert(7, BST);
    Insert(8, BST);
    Insert(6, BST);

    Insert(12, BST);
    Insert(11, BST);
    Insert(13, BST);
    Insert(18, BST);
    Insert(14, BST);
    Insert(21, BST);

    printf("%d\n", FindMin(BST)->Data);
    printf("%d\n", FindMax(BST)->Data);
    return 0;
}

PtrToNode NewNode(int Data) {
    PtrToNode newNode = (PtrToNode)malloc(sizeof(struct TreeNode));
    if (newNode == NULL) {
        printf("Out of Space!!!");
        exit(EXIT_FAILURE);
    }

    newNode->Data = Data;
    newNode->Left = NULL;
    newNode->Right = NULL;

    return newNode;
}

PtrToNode Find(ElementType X, BinTree BST) {
    PtrToNode T = BST;

    while (T) {
        if (X < T->Data) {
            T = T->Left;
        } else if (X > T->Data) {
            T = T->Right;
        } else {
            return T;
        }
    }

    return NULL;
}

PtrToNode FindMin(BinTree BST) {
    PtrToNode T = BST;

    if (T) {
        while(T->Left) {
            T = T->Left;
        }
    }

    return T;
}

PtrToNode FindMax(BinTree BST) {
    PtrToNode T = BST;

    if (T) {
        while(T->Right) {
            T = T->Right;
        }
    }

    return T;
}

PtrToNode Insert(ElementType X, BinTree BST) {
    if (!BST) {
        BST = (PtrToNode)malloc(sizeof(struct TreeNode));
        BST->Data = X;
        BST->Left = NULL;
        BST->Right = NULL;
    } else {
        if (X > BST->Data) {
            BST->Right = Insert(X, BST->Right);
        } else if (X < BST->Data) {
            BST->Left = Insert(X, BST->Left);
        }
    }

    return BST;
}

PtrToNode Delete(ElementType X, BinTree BST) {
    PtrToNode Tmp;

    if (!BST) {
        printf("未找到该元素！！！");
    } else {
        if (X < BST->Data) {
            BST->Left = Delete(X, BST->Left);
        } else if (X > BST->Data) {
            BST->Right = Delete(X, BST->Right);
        } else {
            if (BST->Right && BST->Left) {
                /*
                //Method 1
                Tmp = FindMin(BST->Right);
                BST->Data = Tmp->Data;
                BST->Right = Delete(Tmp->Data, BST->Right);
                */

                //Method 2
                Tmp = FindMax(BST->Left);
                BST->Data = Tmp->Data;
                BST->Left = Delete(Tmp->Data, BST->Left);
            } else {
                Tmp = BST;
                if (!BST->Left) {
                    BST = BST->Right;
                } else if (!BST->Right) {
                    BST = BST->Left;
                }

                free(Tmp);
            }
        }
    }

    return BST;
}
