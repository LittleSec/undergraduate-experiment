#include<stdio.h>
int main()
{
    int a[10]={2,3,4,5,6,7,8,9,10,12};
    int x,i;
    int find(int b,int a[]);
    printf("原始数列是：");
    printf("%d",a[0]);
    for(i=1;i<10;i++)
        printf(",%d",a[i]);
    printf("\n请输入一个数:");
    scanf("%d",&x);
    find(x,a);
    return 0;
}

int find(int b,int a[])
{
    int begin,end,mid;
    for(begin=0,end=9;;)
    {
        mid=(begin+end)/2;
        if(b==a[mid])
            break;
        else if(b>a[mid])
            begin=mid+1;
        else
            end=mid-1;
        if(end<begin)
            break;
    }
    if(b==a[mid])
        printf("该数是数组中第%d个元素的值",mid+1);
    if(end<begin)
        printf("该数组中无数.");
}
