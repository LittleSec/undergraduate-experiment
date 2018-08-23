#include<stdio.h>
void main()
{
    int num,year,mouth,day;
    int jusuan(int y,int m,int d);
    printf("计算某日期是该年的第几天\n");
    while(1)
    {
        printf("请输入年.月.日：");
        scanf("%d.%d.%d",&year,&mouth,&day);
        num=jisuan(year,mouth,day);
        printf("%d年%d月%d日是%d年的第%d天。\n",year,mouth,day,year,num);
    }
}

int jisuan(int y,int m,int d)
{
    int num=0,b,a[]={0,31,28,31,30,31,30,31,31,30,31,30,31,30};
    for(b=0;b<m;b++)
        num=num+a[b];
    num=num+d;
    if((y%400==0||y%4==0&&y%100!=0)&&m>2)
        num=num+1;
    return num;
}
