#include<stdio.h>
int main()
{
	int A[] = {-1,2,3,-20,8,1};
	int MaxSum = MaxSubsequenceSum(A,6);
	printf("MaxSum: %d", MaxSum);
	return 0;
}

int MaxSubSum( int A[], int Left, int Right )
{
	int MaxLeftSum, MaxRightSum;
	int MaxLeftBorderSum, MaxRightBorderSum;
	int LeftBorderSum, RightBorderSum;
	int Center, i;
	
	if( Left == Right )
	{
		if( A[Left] > 0 )
			return A[ Left ];
		else
 			return 0;
	}
	
	Center = ( Left + Right ) / 2;
	MaxLeftSum = MaxSubSum( A, Left, Center );
	MaxRightSum = MaxSubSum( A, Center + 1, Right );
	
	MaxLeftBorderSum = 0;
	LeftBorderSum = 0;

	for ( i = Center; i >= Left; i-- )
	{
		LeftBorderSum += A[ i ];

		if( LeftBorderSum > MaxLeftBorderSum )
			MaxLeftBorderSum = LeftBorderSum;
	}

	MaxRightBorderSum = 0;
	RightBorderSum = 0;
	for( i = Center + 1; i <= Right; i++ )
	{
		RightBorderSum += A[ i ];
		if( RightBorderSum > MaxRightBorderSum )
			MaxRightBorderSum = RightBorderSum;
	}

	return Max3( MaxLeftSum, MaxRightSum, MaxLeftBorderSum + MaxRightBorderSum );
	
}

int MaxSubsequenceSum( int A[], int N )
{
	return MaxSubSum( A, 0, N - 1);
}

int Max3( int num1, int num2, int num3)
{
	int max = num1;

	if( max < num2 )
		max = num2;

	if( max < num3 )
		max = num3;

	return max;
}
