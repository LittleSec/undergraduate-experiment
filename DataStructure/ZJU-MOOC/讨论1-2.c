#include<stdio.h>

int count = 0;

//循环法
void PrintN(int n)
{
	int i;
	for (i = 0; i < n; i++)
		printf("%5d", i);
}

//递归法
void PrintN1(int n)
{
	if (n)
	{
		printf("No. %d\n", count++);
		PrintN1(n - 1);
		printf("%5d", n);
	}
}

//比较两法的速度
//比较是否两法对于同样大的数都能跑起来――――使用递归需要考虑栈大小
int main()
{
	int n;
	scanf("%d", &n);
	PrintN1(n);

	return 0;
}
