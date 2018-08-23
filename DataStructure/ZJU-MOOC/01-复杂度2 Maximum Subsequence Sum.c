#include<stdio.h>
#include<stdlib.h>

/*
最大和前面有一段是0
*/

void MaxSubseqSum(int A[], int N)
{
    int ThisSum, MaxSum;
    int i;
    ThisSum = 0;
    MaxSum = -1;
    int Start, End;
    Start = End = 0;
    for(i = 0; i < N; i++){
        ThisSum += A[i];
        if(ThisSum > MaxSum){
            MaxSum = ThisSum;
            End = i;
        }
        else if(ThisSum < 0)
            ThisSum = 0;
    }

    if(MaxSum < 0){
        printf("%d %d %d", 0, A[0], A[N-1]);
        return;
    }

    int temp;
    temp = MaxSum;
    i = End;
    do{
        temp -= A[i];
        i--;
    }while(temp);
    Start = i + 1;
    printf("%d %d %d", MaxSum, A[Start], A[End]);
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
    MaxSubseqSum(A, K);
    free(A);
    return 0;
}
