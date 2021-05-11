#include<stdio.h>

struct Node;
typedef struct Node *PtrToNode;
typedef PtrToNode List;
typedef PtrToNode Position;
typedef int ElementType;

//其中L为表头(header)或者叫做哑结点(dummy node)
List MakeEmpty( List L );
int IsEmpty( List L );
int IsLast( Position P, List L );
Position Find( ElementType X, List L);
void Delete( ElementType X, List L);
Position FindPrevious( ElementType X, List L );
void Insert(ElementType X, List L, Position P );
void DeleteList( List L );
Position Header( List L );
Position First( List L );
Position Advance( Position P);
ElementType Retrieve( Position P );

struct Node{
    ElementType Element;
    Position Next;
};

List MakeEmpty( List L ){
    if(L != NULL)   DeleteList(L);

    L = ( List )malloc( sizeof( struct Node ) );
    if(L==NULL){
        printf("OUT OF MEMORY!!!");
    }

    L->Next = NULL;
    return L;
}

int IsEmpty( List L ){
    return L->Next == NULL;
}

int IsLast(Position P, List L){
    return P->Next == NULL;
}

Position Find(ElementType X, List L){
    Position P;

    P = L->Next;
    while(P != NULL && P->Element != X){
        P = P->Next;
    }

    return P;
}

void Delete(ElementType X, List L){
    Position P, TmpCell;

    P = FindPrevious(X, L);
    //如果返回的是尾结点，那么表示没有找到Element为X的结点

    if( !IsLast(P, L) ){  
        TmpCell = P->Next;
        P->Next = TmpCell->Next;
        free(TmpCell);
    }
}

Position FindPrevious(ElementType X, List L){
    Position P;

    P = L;
    while(P->Next && P->Next->Element != X){
        P = P->Next;
    }

    return P;
}

void Insert(ElementType X, List L, Position P){
    Position TmpCell;

    TmpCell = (Position *)malloc(sizeof(struct Node));
    if(TmpCell == NULL){
        printf("OUT OF MEMORY!!!");
        return;
    }

    TmpCell->Element = X;
    TmpCell->Next = P->Next;
    P->Next = TmpCell;
}

void DeleteList(List L){
    Position P, Tmp;

    P = L->Next;
    L->Next = NULL;
    while(P){
        Tmp = P->Next;
        free(P);
        P = Tmp;
    }
}

Position Header(List L){
    return L;
}

Position First(List L){
    return L->Next;
}

Position Advance(Position P){
    return P->Next;
}

ElementType Retrieve(Position P){
    return P->Element;
}
