#include<stdio.h>
#define M 2

unsigned process(unsigned n)
{
	static unsigned S=1;
	unsigned d,e;
	d=n/M;
	if(d==0)
		e=1;
	else
	{
		S*=M;
		e=M*process(d);
	}
	if (e==1)
        printf("(");
	printf("%d",n%M);
	if (S==e)
        printf(")%d\n",M);
	return(e);
}

void main()
{
	unsigned num;
	scanf("%u",&num);
	printf("(%u)10=",num);
	process(num);
}
