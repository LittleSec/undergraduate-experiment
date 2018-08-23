#include<stdio.h>
void main()
{
    printf("请输入一句英文句子：\n");
    char string[81];
    int i,num=0,word=0;
    char c;
    gets(string);
    for(i=0;(c=string[i])!='\0';i++)
        if(c==' '||c==','||c=='.'||c==':'||c=='"')
            word=0;
        else if(word==0)
        {
            word=1;
            num++;
        }
    printf("There are %d words in this line.\n",num);
}
