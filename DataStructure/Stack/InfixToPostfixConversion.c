#include <stdio.h>
#include <stdlib.h>
#include "fatal.h"

struct Node;
typedef struct Node *PtrToNode;
typedef PtrToNode Stack;
typedef char ElementType;

int IsEmpty(Stack S);
void MakeEmtpy(Stack S);
Stack CreateStack();
void Push(Stack S, ElementType element);
ElementType Top(Stack S);
ElementType Pop(Stack S);
void DisposeStack(Stack S);
void ConvertInfixToPostfix(char *s);
int Precedence(char ch);
int IsOperand(char ch);

struct Node {
    ElementType element;
    PtrToNode next;
};

int main(void) {
    char expression[50];
    gets(expression);

    ConvertInfixToPostfix(expression);
    
    return 0;
}

int IsEmpty(Stack S) {
    return S->next == NULL;
}

void MakeEmtpy(Stack S) {
    if (S != NULL) {
        while (S->next) {
            Pop(S);
        }
    }
}

Stack CreateStack() {
    Stack S;
    
    S = (Stack)malloc(sizeof(struct Node));
    if (S == NULL) {
        Error("Out of space!!!");
    }
    S->next = NULL;

    return S;
}

void Push(Stack S, ElementType element) {
    PtrToNode Tmp;

    Tmp = (PtrToNode)malloc(sizeof(struct Node));
    if (Tmp == NULL) {
        Error("Out of Space");
    }
    
    Tmp->element = element;
    Tmp->next = S->next;
    S->next = Tmp; 
}

ElementType Top(Stack S) {
    return S->next->element;
}

ElementType Pop(Stack S) {
    int element;
    PtrToNode Tmp;

    if (S == NULL)
        Error("Empty Stack");
    
    Tmp = S->next;
    element = Tmp->element;
    S->next = S->next->next;
    free(Tmp);
    
    return element;
}

void DisposeStack(Stack S) {
    if (S != NULL) {
        MakeEmtpy(S);
        free(S);
    }
}

void ConvertInfixToPostfix(char *s) {
    Stack S = CreateStack();

    int flag = 0;

    while (*s) {
        if (*s == ' ') {
            *s++;
            continue;
        }else if (IsOperand(*s)) {
            printf("%c ", *s);
        } else if (*s == '(') {
            Push(S, *s);
        } else if (*s == ')') {
            while (!IsEmpty(S) && Top(S) != '(') {
                printf("%c", Pop(S));
            }

            if (!IsEmpty(S) && Top(S) != '(') {
                Error("Invalid Expression");
            } else {
                //pop '(', cuz it don't need to be output
                Pop(S); 
            }
        } else {
            while (!IsEmpty(S) && Precedence(*s) <= Precedence(Top(S))) {
                printf("%c", Pop(S));
            }

            Push(S, *s);
        }

        *s++;
    }

    while (!IsEmpty(S)) {
        printf("%c", Pop(S));
    }
}

/* This funciton is to return precendece of 
    given operator
    Higher the return value, higher the precedence 
    Return -1 when given wrong input
*/
int Precedence(char ch) {
    if (ch == '+' || ch == '-')
        return 1;
    else if (ch == '*' || ch == '/')
        return 2;
    else if (ch == '^')
        return 3;
   
    return 0;
}

/*
    This function is to check 
    if the given charactor is 
    operand 
*/
int IsOperand(char ch) {
    if ((ch >= '0' && ch <= '9') || (ch >= 'a' && ch <= 'z') || (ch >= 'A' && ch <= 'Z')) {
        return 1;
    }

    return 0;
}