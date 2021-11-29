#include <stdio.h>
#include <stdlib.h>
#include <stdbool.h>

#define MaxTree 10
#define ElementType char
#define Tree int

struct TreeNode {
    ElementType Element;
    Tree Left;
    Tree Right;
}T1[MaxTree], T2[MaxTree];

bool check[MaxTree];

//utility function to return the root of new tree
Tree BuildTree(struct TreeNode T[]);
//utility function to check if two trees are isomorphic
bool Isomorphic (Tree R1, Tree R2);

int main() {
    //R1 and R2 are roots
    Tree R1, R2;

    R1 = BuildTree(T1);
    R2 = BuildTree(T2);
    if (Isomorphic(R1, R2)) printf("Yes\n");
    else printf("No\n");

    return 0;
}

Tree BuildTree(struct TreeNode T[]) {
    Tree Root;

    int N;
    scanf("%d", &N);
    if (N) {
        // utility function to check if tree node has been traverse to find the root of tree
        // init check array
        for (int i = 0; i < N; ++i) {
            check[i] = false;
        }

        char left, right;
        for (int i = 0; i < N; ++i) {
            scanf("\n%c %c %c", &T[i].Element, &left, &right);
            if (left != '-') {
                T[i].Left = left - '0';
                check[T[i].Left] = true;
            } else {
                T[i].Left = -1;
            }

            if (right != '-') {
                T[i].Right = right - '0';
                check[T[i].Right] = true;
            } else {
                T[i].Right = -1;
            }
        }

        for (int i = 0; i < N; ++i) {
            if (!check[i]) {
                Root = i;
                break;
            }
        }
    }

    return Root;
}

bool Isomorphic(Tree R1, Tree R2) {
    if (R1 == -1 && R2 == -1) {
        return true;
    }

    if ((R1 == -1 && R2 != -1) || (R1 != -1 && R2 == -1)) {
        return false;
    }

    //check if two trees' root are same
    if (T1[R1].Element != T2[R2].Element) {
        return false;
    }

    if ((T1[R1].Left == -1) && (T2[R2].Left == -1)) {
        return Isomorphic(T1[R1].Right, T2[R2].Right);
    }

    if (((T1[R1].Left != -1) && (T2[R2].Left != -1)) && ((T1[T1[R1].Left].Element == T2[T2[R2].Left].Element))) {
        return Isomorphic(T1[R1].Left, T2[R2].Left) && Isomorphic(T1[R1].Right, T2[R2].Right);
    } else {
        return Isomorphic(T1[R1].Left, T2[R2].Right) && Isomorphic(T1[R1].Right, T2[R2].Left);
    }
}