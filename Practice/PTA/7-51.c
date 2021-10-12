#include <stdio.h>
#include <stdlib.h>
#include <string.h>

typedef struct Node *List;
typedef struct Node *node;
List CreateList();
List MergeLists(List L1, List L2);

struct Node
{
    int value;
    struct Node *next;
};

void printList(List L)
{
    if (L != NULL)
    {
        while (L)
        {
            if (L->next == NULL)
            {
                printf("%d", L->value);
            }
            else
            {
                printf("%d ", L->value);
            }
            L = L->next;
        }
    }
    else
    {
        printf("NULL");
    }
}

int main()
{
    List L1 = CreateList();
    List L2 = CreateList();
    List L3 = MergeLists(L1, L2);

    printList(L3);
    return 0;
}

List CreateList()
{
    List L = (struct Node *)malloc(sizeof(struct Node));
    node p, tmp;
    p = L;

    int val;
    scanf("%d", &val);
    while (val != -1)
    {
        tmp = (struct Node *)malloc(sizeof(struct Node));
        tmp->value = val;
        tmp->next = NULL;
        p->next = tmp;
        p = tmp;

        scanf("%d", &val);
    }

    tmp = L;
    L = L->next;
    free(tmp);
    return L;
}

List MergeLists(List L1, List L2)
{
    List L3 = (struct Node *)malloc(sizeof(struct Node));
    node p, tmp;
    p = L3;

    while (L1 && L2)
    {
        if (L1->value > L2->value)
        {
            p->next = L2;
            p = p->next;
            L2 = L2->next;
        }
        else
        {
            p->next = L1;
            p = p->next;
            L1 = L1->next;
        }
    }

    if (L1)
        p->next = L1;
    if (L2)
        p->next = L2;

    tmp = L3;
    L3 = L3->next;
    free(tmp);
    return L3;
}