#include<stdio.h>
void main()
{
    int n,N;
    printf("绘制星号图案，请输入n的值（n<=9）：");
    scanf("%d",&n);
    N=n-1;
    int dizeng(int a);
    int dijian(int a);
    dizeng(n);
    dijian(N);
}

int dizeng(int a)
{
    int i,j,k;
    for(i=1;a>0;a--,i++)
    {
        for(k=1;k<=a-1;k++)
            printf(" ");
		for(j=1;j<=2*i-1;j++)
			printf("*");
		putchar('\n');
    }
    return 0;
}

int dijian(int a)
{
    int i,j,k;
    for(i=1;a>0;a--,i++)
    {
        for(k=1;k<=i;k++)
            printf(" ");
        for(j=2*a-1;j>0;j--)
            printf("*");
        putchar('\n');
    }
    return 0;
}
