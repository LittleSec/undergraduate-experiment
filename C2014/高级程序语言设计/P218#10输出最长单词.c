#include<stdio.h>
#include<string.h>
void main()
{
    char str[100];
    printf("请输入一句英文句子：\n");
    gets(str);
    void search(char a[],int n);
    search(str,100);
}

void search(char a[],int n)
{
    int i=0,j=0,t,k,word=0;
    char b[10][20];
    for(k=0;a[k]!='\0';k++)
    {
        if(a[k]==' ')
        {
            if(word)
            {
                b[j][i]='\0';
                word=0;
            }
        }
        else
        {
            if(word)
                b[j][i]=a[k];
            else
            {
                j++;
                i=0;
                b[j][i]=a[k];
            }
            word=1;
            i++;
        }
    }
    b[j][i]='\0';   //不是i+1，因为之前已经i++了。
    t=j;
    printf("该英文句子中最长的单词为：");
    b[0][0]='0';
    for(j=1;j<=t;j++)
    {
        if(strlen(b[j])>strlen(b[0]))
            strcpy(b[0],b[j]);
    }
    printf("%s",b[0]);
}
