#include<stdio.h>
void main()
{
    //char str[100];printf("请输入一个字符串：\n");gets(str);
    char str[]={"A123x456 17960? 302tab5876"};
    void search(char a[],int n);
    search(str,100);
}

void search(char a[],int n)
{
    int i=0,j=0,t,k,leap=0;
    char b[10][20];
    for(k=0;a[k]!='\0';k++)
    {
        if(a[k]>=48&&a[k]<=57)
        {
            if(leap)
            {
                b[j][i]=a[k];
                i++;
            }
            else
            {
                j++;
                i=0;
                b[j][i]=a[k];
                i++;
                leap=1;
            }
        }
        else
        {
            if(leap)
            {
                b[j][i]='\0';
                leap=0;
            }
        }

    }
    b[j][i]='\0';   //不是i+1，因为之前已经i++了。
    t=j;
    printf("该字符串共有%d个整数\n分别是：\n",t);
    for(j=1;j<=t;j++)
    {
        for(i=0;b[j][i]!='\0';i++)
            printf("%c",b[j][i]);
        printf("\n");
    }
}
