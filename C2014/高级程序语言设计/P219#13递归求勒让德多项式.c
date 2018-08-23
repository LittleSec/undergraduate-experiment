#include<stdio.h>
void main()
{
    double P(int n,double x);
    int n;
    double x,y;
    printf("请输入n和x的值：");
    scanf("%d %lf",&n,&x);
    y=P(n,x);
    printf("P%d(%lf)=%lf",n,x,y);
}

double P(int n,double x)
{
    double y;
    if(n<0)
        printf("error");
    else if(n==0)
        y=1;
    else if(n==1)
        y=x;
    else
        y=((2*n-1)*x-P(n-1,x)-(n-1)*P(n-2,x))/n;
    return y;
}
