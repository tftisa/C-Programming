#include <stdio.h>
#include <stdlib.h>

typedef struct PolyNode *Polynomial;

Polynomial CreatePoly();
Polynomial PolyAdd(Polynomial P1, Polynomial P2);
Polynomial PolyMult(Polynomial P1, Polynomial P2);
void PrintPoly(Polynomial P);
void Attach(int coef, int expon, Polynomial *pRear);
int Compare(int a, int b);

struct PolyNode {
    int coef;
    int exp;
    struct PolyNode *next;
};

int main() {
    Polynomial P1 = CreatePoly();
    Polynomial P2 = CreatePoly();

    PrintPoly(PolyMult(P1, P2));
    printf("\n");

    PrintPoly(PolyAdd(P1, P2));
    return 0;
}

Polynomial CreatePoly() {
    Polynomial p, rear, tmp;
    p = (struct PolyNode*)malloc(sizeof(struct PolyNode));
    p->next = NULL;
    rear = p;

    int N, c, e;
    scanf("%d", &N);
    while (N--) {
        scanf("%d %d", &c, &e);
        if (c) {
            Attach(c, e, &rear);
        }
    }

    tmp = p;
    p = p->next;
    free(tmp);
    return p;
}

Polynomial PolyAdd(Polynomial P1, Polynomial P2) {
    Polynomial tmp, rear, front, p1, p2;
    front = (Polynomial)malloc(sizeof(struct PolyNode));
    rear = front;
    p1 = P1;
    p2 = P2;

    while (p1 && p2) {
        switch (Compare(p1->exp, p2->exp)) {
            case 1:
                Attach(p1->coef, p1->exp, &rear);
                p1 = p1->next;
            
            case 0:
                if (p1->coef + p2->coef) {
                    Attach(p1->coef + p2->coef, p1->exp, &rear);
                }
                p1 = p1->next;
                p2 = p2->next;
            
            case -1:
                Attach(p2->coef, p2->exp, &rear);
                p2 = p2->next;
        }
    }

    while (p1) {
        Attach(p1->coef, p1->exp, &rear);
        p1 = p1->next;
    }

    while (p2) {
        Attach(p2->coef, p2->exp, &rear);
        p2 = p2->next;
    }

    tmp = front;
    front = front->next;
    free(tmp);
    return front;
}

Polynomial PolyMult(Polynomial P1, Polynomial P2) {
    if (!P1 || !P2) return NULL;
    
    Polynomial front, rear, tmp, p, p1, p2;
    front = (Polynomial)malloc(sizeof(struct PolyNode));
    front->next = NULL;
    rear = front;

    p1 = P1;
    p2 = P2;

    int c, e;
    while (p2) {
        c = p1->coef * p2->coef;
        e = p1->exp + p2->exp;
        Attach(c, e, &rear);
        p2 = p2->next;
    }
    p1 = p1->next;

    while (p1) {
        rear = front;
        p2 = P2;
        while (p2) {
            c = p1->coef * p2->coef;
            e = p1->exp + p2->exp;

            while (rear->next && rear->next->exp > e) {
                rear = rear->next;
            }

            if (rear->next && e == rear->next->exp) {
                if (c + rear->next->coef) {
                    rear->next->coef += c;
                } else {
                    tmp = rear->next;
                    rear->next = tmp->next;
                    free(tmp);
                }
            } else {
                tmp = (Polynomial)malloc(sizeof(struct PolyNode));
                tmp->coef = c;
                tmp->exp = e;
                tmp->next = rear->next;
                rear->next = tmp;
                rear = tmp;
            }

            p2 = p2->next;
        }

        p1 = p1->next;
    }

    tmp = front;
    front = front->next;
    free(tmp);
    return front;
}

void Attach(int coef, int expon, Polynomial *pRear) {
    Polynomial P = (struct PolyNode*)malloc(sizeof(struct PolyNode));
    P->coef = coef;
    P->exp = expon;
    P->next = NULL;
    (*pRear)->next = P;
    *pRear = P;
}

void PrintPoly(Polynomial P) {
    Polynomial p = P;
    if (p) {
        int flag = 0;
        while (p) {
            if (!flag)
                flag = 1;
            else 
                printf(" ");
            
            printf("%d %d", p->coef, p->exp);
            p = p->next;
        }
    } else {
        printf("0 0");
    }
}

int Compare(int a, int b) {
    if (a > b) {
        return 1;
    } else if (a < b) {
        return -1;
    } else {
        return 0;
    }
}
