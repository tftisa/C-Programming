#include<stdio.h>
int MaxSubseqSum(int A[], int k);

int main()
{
    int k, i;
    scanf("%d", &k);
    
    int A[k];
    for(int i = 0; i < k; i++){
        scanf("%d", &A[i]);
    }
    
    int MaxSum = MaxSubseqSum(A, k);
    printf("%d", MaxSum);
    
    return 0;
}


int MaxSubseqSum(int A[], int k)
{
    int MaxSum = 0, ThisSum = 0;
    
    for(int i = 0; i < k; i++){
        ThisSum += A[i];
        
        if(ThisSum < 0)
            ThisSum = 0;
        else if(ThisSum > MaxSum)
            MaxSum = ThisSum;
    }
    
    return MaxSum;
}

