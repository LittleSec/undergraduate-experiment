#include<stdio.h>
void main()
{
    float store[3][5],aver1,aver2;
    int i,j,a;
    float average1(float a[][5],int n);
    float average2(float a[][5],int n);
    int max(float a[][5]);
    float fangcha(float a[][5]);
    for(i=0;i<3;i++)
    {
        printf("请输入第%d个学生的5门成绩：",i+1);
        for(j=0;j<5;j++)
            //scanf("%f",&store[i][j]);
            store[i][j]=70;
    }
    for(i=0;i<3;i++)
    {
        aver1=average1(store,i);
        printf("第%d个学生的平均分是：%.2f\n",i+1,aver1);
    }
    for(i=0;i<5;i++)
    {
        aver2=average2(store,i);
        printf("第%d门课的平均分是：%.2f\n",i+1,aver2);
    }
    a=max(store);
    i=a/10;
    j=a%10;
    printf("最高分为：%.2f，是第%d个学生的第%d门课程。\n",store[i-1][j-1],i,j);
    printf("方差为：%.2f\n",fangcha(store));
}

float average1(float a[][5],int n)
{
    int i,sum=0;
    float aver;
    for(i=0;i<5;i++)
        sum=sum+a[n][i];
    aver=sum/5;
    return aver;
}

float average2(float a[][5],int n)
{
    int j,sum=0;
    float aver;
    for(j=0;j<3;j++)
        sum=sum+a[j][n];
    aver=sum/3;
    return aver;
}

int max(float a[][5])
{
    int i,j,m,n,b=0;
    for(i=0;i<3;i++)
        for(j=0;j<5;j++)
            if(a[i][j]>b)
            {
                b=a[i][j];
                n=i+1;
                m=j+1;
            }
    return (n*10+m);
}

float fangcha(float a[][5])
{
    int i;
    float b=0,c=0,d;
    float average1(float a[][5],int n);
    for(i=0;i<3;i++)
    {
        d=average1(a,i);
        b=b+d;
        c=c+d*d;
    }
    return c/i-b/i*b/i;
}
