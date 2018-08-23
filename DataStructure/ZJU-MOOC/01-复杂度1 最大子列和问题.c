#include<stdio.h>
#include<stdlib.h>

int MaxSubseqSum(int A[], int N)
{
    int ThisSum, MaxSum;
    int i;
    ThisSum = MaxSum = 0;
    for(i = 0; i < N; i++){
        ThisSum += A[i];
        if(ThisSum > MaxSum)
            MaxSum = ThisSum;
        else if(ThisSum < 0)
            ThisSum = 0;
    }
    return MaxSum;
}

int main()
{
    long int K;
    scanf("%ld", &K);
    int *A;
    A = (int*)malloc(K * sizeof(int));
    int i;
    for(i = 0; i < K; i++)
        scanf("%d", &A[i]);
    printf("%d", MaxSubseqSum(A ,K));
    return 0;
}
