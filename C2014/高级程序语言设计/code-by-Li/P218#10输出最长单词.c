#include<stdio.h>
#include<string.h>

int alph(char c)
{
	if((c>='a'&&c<='z')||(c>='A'&&c<='Z'))
		return(1);
	else
		return(0);
}

int longest(char string[])
{
	int len=0,length=0,flag=1,place=0,point;
	unsigned int i;
	for(i=0;i<=strlen(string);i++)
		if(alph(string[i]))
			if(flag)
			{
				point=i;    //point记录新单词首字母在原始字符串中的位置。
				flag=0;     //flag=1即当前字符为空格，flag=0即当前字符为字母。
			}
			else
				len++;      //len用于记录当前单词的长度。
		else
		{
			if(len>length)
			{
				length=len;
				place=point;    //place用于记录最长单词的首字母在原始字符串中的位置。
			}
			flag=1;
			len=0;
		}
	return(place);
}

void main()
{
	int i;
	char line[100];
	printf("in:");
	gets(line);
	printf("The longest word is:");
	for(i=longest(line);alph(line[i]);i++)      //直到空格就停止输出。
		printf("%c",line[i]);
	putchar('\n');
}
