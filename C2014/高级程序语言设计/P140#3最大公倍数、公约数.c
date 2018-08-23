#include<stdio.h>
#include<stdlib.h>
void main()
{
    int m,n,y,b;
    int gys(int a,int b);
    printf("请输入两个非负整数（m,n）：");
    scanf("%d,%d",&m,&n);
    if((m<0||n<0)||(m==0&&n==0))
    {
         printf("输入错误。\n");
         exit(0);
    }
    y=gys(m,n);
    b=m*n/y;
    printf("最大公约数是：%d\n",y);
    printf("最小公倍数是：%d\n",b);
}

int gys(int a,int b)
{
    int r;
    while(b!=0)
    {
        r=a%b;
        a=b;
        b=r;
    }
    return a;
}
