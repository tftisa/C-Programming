#include <stdlib.h>
#include "fatal.h"

struct Node;
typedef struct Node *PtrToNode;
typedef PtrToNode List;
typedef PtrToNode Position;
typedef int ElementType;

List MakeEmpty(List L);
int IsEmpty(List L);
int IsLast(Position P, List L);
Position Find(ElementType X, List L);
void Delete(ElementType X, List L);
Position FindPrevious(ElementType X, List L);
void Insert(ElementType X, List L, Position P);
void DeleteList(List L);

struct Node {
    ElementType Element;
    Position Next;
};

/*Return true if L is empty */
int IsEmpty(List L) { return L->Next == NULL; }

/*return true if P is the last position in list L*/

int IsLast(Position P, List L) { return P->Next == NULL; }

/*Return Position of X in L; NULL if not found */
Position Find(ElementType X, List L) {
    Position P;

    P = L->Next;
    while (P != NULL && P->Element != X) {
        P = P->Next;
    }

    return P;
}

/*Delete first occurrence of X from a list */
void Delete(ElementType X, List L) {
    Position P, TmpCell;

    P = FindPrevious(X, L);

    while (P != NULL) {
        TmpCell = P->Next;
        P->Next = TmpCell->Next;
        free(TmpCell);
    }
}

/*If X is not found, then Next field of returned */
Position FindPrevious(ElementType X, List L) {
    Position P;

    P = L;

    while (P->Next != NULL && P->Next->Element != X) {
        P = P->Next;
    }

    return P;
}

/*Insert (after legal position P) */
void Insert(ElementType X, List L, Position P) {
    Position TmpCell;

    TmpCell = malloc(sizeof(struct Node));
    if (TmpCell == NULL) FatalError("Out of space!!!");

    TmpCell->Element = X;
    TmpCell->Next = P->Next;
    P->Next = TmpCell;
}

void DeleteList(List L) {
    Position P, Tmp;

    P = L->Next;
    L->Next = NULL;

    while (P != NULL) {
        Tmp = P->Next;
        free(P);
        P = Tmp;
    }
}
