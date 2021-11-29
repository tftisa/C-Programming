#include <stdio.h>
#include <stdlib.h>

struct TreeNode;
typedef struct TreeNode *PtrToNode;
typedef PtrToNode Tree;
typedef int ElementType;

struct TreeNode {
    ElementType Data;
    PtrToNode Left;
    PtrToNode Right;
};

PtrToNode newNode(ElementType Data);
void PreOrderTraversal(Tree tree);
void InOrderTraversal(Tree tree);
void PostOrderTraversal(Tree tree);
void PreOrderPrintLeaves(Tree tree);
void InOrderPrintLeaves(Tree tree);
void PostOrderPrintLeaves(Tree tree);
int Height(Tree tree);

int main () {
    /* Tree root = newNode('+');
    root->Left = newNode('+');
    root->Left->Left = newNode('a');
    root->Left->Right = newNode('*');
    root->Left->Right->Left = newNode('b');
    root->Left->Right->Right = newNode('c');

    root->Right = newNode('*');
    root->Right->Right = newNode('g');
    root->Right->Left = newNode('+');
    root->Right->Left->Left = newNode('*');
    root->Right->Left->Right = newNode('f');
    root->Right->Left->Left->Left = newNode('d');
    root->Right->Left->Left->Right = newNode('e'); */

    Tree root = newNode(1);
    root->Left = newNode(2);
    root->Right = newNode(3);
    root->Left->Left = newNode(4);
    root->Left->Right = newNode(5);

    printf("PreOrder traversal of binary tree is \n");
    PreOrderTraversal(root);

    printf("\nInOrder traversal of binary tree is \n");
    InOrderTraversal(root);

    printf("\nPostOrder traversal of binary tree is \n");
    PostOrderTraversal(root);

    printf("\nPreOrder print leaves of binary tree is \n");
    PreOrderPrintLeaves(root);

    printf("\nInOrder print leaves of binary tree is \n");
    InOrderPrintLeaves(root);

    printf("\nPostOrder print leaves of binary tree is \n");
    PostOrderPrintLeaves(root);

    printf("\n The height of binary tree is \n");
    printf("%d\n", Height(root));

    return 0;
}

PtrToNode newNode(ElementType Data) {
    PtrToNode node = (PtrToNode)malloc(sizeof(struct TreeNode));
    if (node == NULL) {
        printf("Out of space!!!"); 
        exit(EXIT_FAILURE);
    }
    node->Data = Data;
    node->Left = NULL;
    node->Right = NULL;

    return node;
}

void PreOrderTraversal(Tree tree) {
    if (tree) {
        printf("%d ", tree->Data);
        PreOrderTraversal(tree->Left);
        PreOrderTraversal(tree->Right);
    }

}

void InOrderTraversal(Tree tree) {
    if (tree) {
        InOrderTraversal(tree->Left);
        printf("%d ", tree->Data);
        InOrderTraversal(tree->Right);
    }
}

void PostOrderTraversal(Tree tree) {
    if (tree) {
        PostOrderTraversal(tree->Left);
        PostOrderTraversal(tree->Right);
        printf("%d ", tree->Data);
    }
}

void PreOrderPrintLeaves(Tree tree) {
    if (tree) {
        if (!tree->Left && !tree->Right)
            printf("%d ", tree->Data);
        
        PreOrderTraversal(tree->Left);
        PreOrderTraversal(tree->Right);
    }
}

void InOrderPrintLeaves(Tree tree) {
    if (tree) {
        InOrderTraversal(tree->Left);

        if (!tree->Left && !tree->Right) 
            printf("%c ", tree->Data);

        InOrderTraversal(tree->Right);
    }
}

void PostOrderPrintLeaves(Tree tree) {
    if (tree) {
        PostOrderTraversal(tree->Left);
        PostOrderTraversal(tree->Right);

        if (!tree->Left && !tree->Right) 
            printf("%d ", tree->Data);
    }
}

int Height(Tree tree) {
    int leftHeight, rightHeight, maxHeight;

    if (tree) {
        leftHeight = Height(tree->Left);
        rightHeight = Height(tree->Right);
        maxHeight = leftHeight > rightHeight ? leftHeight : rightHeight;
        return maxHeight + 1;
    } else {
        return 0;
    }
}