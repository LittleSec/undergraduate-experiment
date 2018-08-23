#include<stdio.h>
void main()
{
    int a1,a2,b,c=0,e,d,i;
    printf("请输入一个数：");
    scanf("%d",&a1);
    a2=a1;
    printf("逆序输出为：");
    while(a1!=0)
    {
        b=a1%10;
        a1=a1/10;
        printf("%d",b);
        c++;
    }
    printf("。\n它是一个%d位数。\n",c);
    for(i=0,d=1;i<c-1;i++)
        d=d*10;
    printf("它的各位数字为：");
    while(c!=0)
    {
        e=a2/d;
        a2=a2-e*d;
        d=d/10;
        printf("%d ",e);
        c--;
    }
    putchar('\n');
}
