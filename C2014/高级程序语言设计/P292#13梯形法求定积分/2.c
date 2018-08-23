#include<stdio.h>
#include<stdlib.h>
#include<math.h>
#define N 1000   //将区间分成N份
void main()
{
    int a,i;
    float b,c;
    float cosx(float a,float b);
    float sinx(float a,float b);
    float expx(float a,float b);
    printf("1.sin(x)    2.cos(x)    3.exp(x)    0.exit\n");
    printf("请选择：");
    scanf("%d",&a);
    while(a)
    {
        printf("请输入积分下限：");
        scanf("%f",&b);
        printf("请输入积分上限：");
        scanf("%f",&c);
        switch(a)
        {
            case 1:printf("该sin(x)的定积分为：%f\n",sinx(b,c));break;
            case 2:printf("该cos(x)的定积分为：%f\n",cosx(b,c));break;
            case 3:printf("该exp(x)的定积分为：%f\n",expx(b,c));break;
            default:printf("没有对应的函数，请重新选择！\n");break;
        }
        for(i=0;i<80;i++)
            printf("=");
        printf("1.sin(x)    2.cos(x)    3.exp(x)    0.exit\n");
        printf("请选择：");
        scanf("%d",&a);
    }
    while(!a)
        exit(0);
}

float cosx(float a,float b)
{
    float i,sum;
    int j;
    i=(b-a)/N;
    for(j=0;j<N;j++)
        sum=sum+(cos(a+j*i)+cos(a+(j+1)*i))*i/2;
    return sum;
}

float sinx(float a,float b)
{
    float i,sum;
    int j;
    i=(b-a)/N;
    for(j=0;j<N;j++)
        sum=sum+(sin(a+j*i)+sin(a+(j+1)*i))*i/2;
    return sum;
}

float expx(float a,float b)
{
    float i,sum;
    int j;
    i=(b-a)/N;
    for(j=0;j<N;j++)
        sum=sum+(exp(a+j*i)+exp(a+(j+1)*i))*i/2;
    return sum;
}
