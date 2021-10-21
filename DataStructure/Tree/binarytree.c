#include <stdio.h>
#include <stdlib.h>

struct TreeNode;
typedef struct TreeNode *PtrToNode;
typedef PtrToNode Tree;

struct TreeNode {
    int Data;
    PtrToNode Left;
    PtrToNode Right;
};

PtrToNode newNode(int Data);
void PreOrderTraversal(Tree tree);
void InOrderTraversal(Tree tree);
void PostOrderTraversal(Tree tree);

int main () {
    Tree root = newNode(1);
    root->Left = newNode(2);
    root->Right = newNode(3);
    root->Left->Left = newNode(4);
    root->Left->Right = newNode(5);

    printf("PreOrder traversal of binary tree is \n");
    PreOrderTraversal(root);

    printf("\nInOrder traversal of binary tree is \n");
    InOrderTraversal(root);

    printf("\nPostOrder Traversal of binary tree is \n");
    PostOrderTraversal(root);

    return 0;
}

PtrToNode newNode(int Data) {
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