#include <stdio.h>
#include <stdlib.h>

typedef int ElementType;

struct TreeNode;
typedef struct TreeNode *PtrToTreeNode;
typedef PtrToTreeNode Tree;

struct StackNode;
typedef struct StackNode *PtrToStackNode;
typedef PtrToStackNode Stack;

int IsEmpty(Stack S);
Stack CreateStack(void);
PtrToTreeNode Top(Stack S);
void Push(PtrToTreeNode TreeNode, Stack S);
PtrToTreeNode Pop(Stack S);

PtrToTreeNode NewTreeNode(ElementType X);
void PreOrderTraversal(Tree BT);
void InOrderTraversal(Tree BT);
void PostOrderTraversal(Tree BT);

struct TreeNode {
    ElementType data;
    PtrToTreeNode left;
    PtrToTreeNode right;
};

struct StackNode {
    PtrToTreeNode treeNode;
    PtrToStackNode next;
};

int main() {
    Tree BT = NewTreeNode(1);
    BT->left = NewTreeNode(2);
    BT->right = NewTreeNode(3);
    BT->left->left = NewTreeNode(4);
    BT->left->right = NewTreeNode(5);

    printf("PreOrder traversal of binary tree\n");
    PreOrderTraversal(BT);

    printf("\nInOrder tarversal of binary tree\n");
    InOrderTraversal(BT);

    printf("\nPostOrder traversal of binary tree\n");
    PostOrderTraversal(BT);

    return 0;
}

int IsEmpty(Stack S) {
    return S->next == NULL;
}

Stack CreateStack(void) {
    Stack S = (Stack)malloc(sizeof(struct StackNode));
    if (S == NULL) {
        printf("Out of space!!!!");
        exit(EXIT_FAILURE);
    }
    S->next = NULL;
}

void Push(PtrToTreeNode TreeNode, Stack S) {
    PtrToStackNode stackNode = (PtrToStackNode)malloc(sizeof(struct StackNode));
    if (stackNode == NULL) {
        printf("Out of space!!!");
        exit(EXIT_FAILURE);
    }
    
    stackNode->treeNode = TreeNode;
    stackNode->next = S->next;
    S->next = stackNode;
}

PtrToTreeNode Top(Stack S) {
    return S->next->treeNode;
}

PtrToTreeNode Pop(Stack S) {
    if (!IsEmpty(S)) {
        PtrToStackNode stackNode = S->next;
        PtrToTreeNode treeNode = (PtrToTreeNode)malloc(sizeof(struct TreeNode));
        treeNode->data = stackNode->treeNode->data;
        treeNode->left = stackNode->treeNode->left;
        treeNode->right = stackNode->treeNode->right;
        
        S->next = S->next->next;
        free(stackNode);
        return treeNode;
    }

    return NULL;
}

PtrToTreeNode NewTreeNode(ElementType X) {
    PtrToTreeNode newNode = (PtrToTreeNode)malloc(sizeof(struct TreeNode));
    if (newNode == NULL) {
        printf("Out of space!!!");
        exit(EXIT_FAILURE);
    }
    newNode->data = X;
    newNode->left = NULL;
    newNode->right = NULL;

    return newNode;
}

void PreOrderTraversal(Tree BT) {
    PtrToTreeNode T = BT;
    Stack S = CreateStack();
    Push(T, S);

    while (T || !IsEmpty(S)) {
        T = Pop(S);
        while (T) {
            printf("%d ", T->data);
            if (T->right) {
                Push(T->right, S);
            }

            T = T->left;
        }
    }
}

void InOrderTraversal(Tree BT) {
    PtrToTreeNode T = BT;
    Stack S = CreateStack();
    
    while (T || !IsEmpty(S)) {
        while (T) {
            Push(T, S);
            T = T->left;
        }

        if (!IsEmpty(S)) {
            T = Pop(S);
            printf("%d ", T->data);
            T = T->right;
        }
    }
}

void PostOrderTraversal(Tree BT) {
    PtrToTreeNode cur = BT, prev = NULL;
    Stack S = CreateStack();

    while (cur != NULL || !IsEmpty(S)) {
        if (cur != NULL) {
            Push(cur, S);
            cur = cur->left;
        } else {
            cur = Top(S);
            if (cur->right == NULL || cur->right == prev) {
                Pop(S);
                printf("%d ", cur->data);
                prev = cur;
                cur = NULL;
            } else {
                cur = cur->right;
            }
        }
    }
}