#include<stdio.h>
#include<stdlib.h>

struct PolyNode{
	int coef;    //系数
	int exp;     //指数
	struct PolyNode *next;
};
typedef struct PolyNode *Polynomial;
typedef struct PolyNode *List;

Polynomial PolyAdd(Polynomial P1, Polynomial P2);
void Attach(int coef, int exp, Polynomial *cur);
Polynomial PolyCreate(int n);
void PrintList(List L);
int Compare(int a, int b){
	if(a > b){
		return 1;
	}

	if(a == b){
		return 0;
	}

	if(a < b){
		return -1;
	}
}

int main(){
	Polynomial L1 = PolyCreate(3);
	Polynomial L2 = PolyCreate(3);

	printf("L3: \n");
	PrintList(PolyAdd(L1, L2));
	return 0;
}

Polynomial PolyCreate(int n){
	List L = (List)malloc(sizeof(struct PolyNode));
	L->next = NULL;
	Polynomial cur = L;

	while(n--){
		Polynomial P = (Polynomial)malloc(sizeof(struct PolyNode));
		P->next = NULL;
		printf("Please enter coef: ");
		scanf("%d", &P->coef);

		printf("Please enter expon: ");
		scanf("%d", &P->exp);

		cur->next = P;
		cur = P;
	}

	return L;
}

void PrintList(List L){
	if(!L->next)	return;

	Polynomial cur = L->next;
	while(cur){
		printf("coef: %d, exp: %d\n", cur->coef, cur->exp);
		cur = cur->next;
	}
}

Polynomial PolyAdd(Polynomial P1, Polynomial P2){
	Polynomial dummy, cur, temp;
	int sum;
	dummy = (Polynomial)malloc(sizeof(struct PolyNode));
	dummy->next = NULL;
	cur = dummy;
	P1 = P1->next;
	P2 = P2->next;
	while(P1 && P2){
		switch(Compare(P1->exp, P2->exp)){
			case 1:
				Attach(P1->coef, P1->exp, &cur);
				P1 = P1->next;
				break;
			case -1:
				Attach(P2->coef, P2->coef, &cur);
				P2 = P2->next;
				break;
			case 0:
				sum = P1->coef + P1->coef;
				if(!sum)	Attach(sum, P1->exp, &cur);
				P1 = P1->next;
				P2 = P2->next;
		}
	}

	for(; P1; P1 = P1->next)	Attach(P1->coef, P1->exp, &cur);
	for(; P2; P2 = P2->next)	Attach(P2->coef, P2->exp, &cur);

	cur->next = NULL;
	return dummy;
}

//这里cur是指针的指针，因为c语言函数参数的值传递，如果是一维指针，那么无法改变cur所指的那个结点
void Attach(int coef, int exp, Polynomial *cur){
	Polynomial P = (Polynomial)malloc(sizeof(struct PolyNode));
	P->coef = coef;
	P->exp = exp;
	P->next = NULL;

	(*cur)->next = P;
	*cur = P;
}

