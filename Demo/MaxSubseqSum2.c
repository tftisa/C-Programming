#include<stdio.h>
int main()
{
	int A[] = {-1,2,3,-20,8,1};
	int MaxSum = MaxSubseqSum1(A,6);
	printf("MaxSum: %d", MaxSum);
	return 0;
}

int MaxSubseqSum1(int A[], int N)
{
	int ThisSum;
	int MaxSum = 0;

	int i, j, k;
	for( i = 0; i < N; i++){
		ThisSum = 0;
		for( j = i; j < N; j++){
			ThisSum += A[j];
			
			if(ThisSum > MaxSum){
				MaxSum = ThisSum;
			}
		}
	}
	return MaxSum;
}
