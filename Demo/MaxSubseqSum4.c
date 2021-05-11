#include<stdio.h>
int main()
{
	int A[] = {-1,2,3,-20,8,1};
	int MaxSum = MaxSubseqSum4(A,6);
	printf("MaxSum: %d", MaxSum);
	return 0;
}

