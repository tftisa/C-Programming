#include <stdio.h>
#include <stdlib.h>
#include <stdbool.h>

struct Node;
struct QNode;
typedef struct Node *PtrToQueueNode;
typedef PtrToQueueNode Position;
typedef struct QNode *Queue;
typedef int ElementType;

typedef struct TreeNode *PtrToTreeNode;
typedef PtrToTreeNode Tree;

bool IsEmpty(Queue Q);
Queue CreateQueue();
void Enqueue(Queue Q, PtrToTreeNode X);
PtrToTreeNode Dequeue(Queue Q);
void DisposeQueue(Queue Q);
PtrToTreeNode NewTreeNode(ElementType X);
void LevelOrderTraversal(Tree BT);

//define queue structure
struct Node {
    PtrToTreeNode treeNode;
    PtrToQueueNode next;
};

struct QNode {
    PtrToQueueNode front;
    PtrToQueueNode rear;
};

//define tree structure

struct TreeNode {
    ElementType data;
    PtrToTreeNode left;
    PtrToTreeNode right;
};

int main() {
    Tree BT = NewTreeNode(1);
    BT->left = NewTreeNode(2);
    BT->right = NewTreeNode(3);
    BT->left->left = NewTreeNode(4);
    BT->left->right = NewTreeNode(5);

    LevelOrderTraversal(BT);
    
    return 0;
}

void LevelOrderTraversal(Tree BT) {
    if (BT == NULL) return;

    PtrToTreeNode T = BT;
    Queue Q = CreateQueue();
    Enqueue(Q, BT);

    while (!IsEmpty(Q)) {
        T = Dequeue(Q);
        printf("%d ", T->data);
        if (T->left) Enqueue(Q, T->left);
        if (T->right) Enqueue(Q, T->right);
    }
}

bool IsEmpty(Queue Q) {
    return Q->front == NULL;
}

Queue CreateQueue() {
    Queue Q = (Queue)malloc(sizeof(struct QNode));
    if (Q == NULL) {
        printf("Out of space");
        exit(EXIT_FAILURE);
    }

    Q->front = Q->rear = NULL;
    return Q;
}

void Enqueue(Queue Q, PtrToTreeNode X) {
    PtrToQueueNode p = (PtrToQueueNode)malloc(sizeof(struct Node));
    if (p == NULL) {
        printf("Out of space!!!");
        exit(EXIT_FAILURE);
    }
    p->treeNode = X;
    p->next = NULL;
    
    if (Q->front == NULL) {
        Q->front = Q->rear = p;
    } else {
        Q->rear->next = p;
        Q->rear = p;
    }
}

PtrToTreeNode Dequeue(Queue Q) {
    if (!IsEmpty(Q)) {
        PtrToQueueNode p = Q->front;

        if (Q->front == Q->rear) {
            Q->front = Q->rear = NULL;
        } else {
            Q->front = Q->front->next;
        }

        return p->treeNode;
    }

    return NULL;
}


PtrToTreeNode NewTreeNode(ElementType X) {
    PtrToTreeNode treeNode = (PtrToTreeNode)malloc(sizeof(struct TreeNode));
    if (treeNode == NULL) {
        printf("Out of space!!!");
        exit(EXIT_FAILURE);
    }
    treeNode->data = X;
    treeNode->left = NULL;
    treeNode->right = NULL;

    return treeNode; 
}