#include<stdio.h>
static int arr[100];
void main()
{
	void solve(int people,int spacing);
	int people,spacing,i,j=0;
	printf("请输入总人数(2-99):");
	scanf("%d",&people);
	printf("请输入报数(1-10):");
	scanf("%d",&spacing);
	solve(people,spacing);
	printf("\n离开顺序为：\n");
	for(i=people-1;i>=0;i--)
	{
		if(arr[i]==0)
		    printf("%4d",arr[i]+people);
		else
			printf("%4d",arr[i]);
		j++;
		if(j%15==0) printf("\n");
	}
	if(j%15!=0) printf("\n");
}

int change(int number,int spacing,int mancount)
{
	if (number==0) number=mancount-1;
	return((number+spacing)%mancount);
}

void solve(int people,int spacing)
{
	int i,j,temp,sum=0;
	for(i=2;i<=people;i++)
	{
		sum+=i-1;
		temp=sum;
		for(j=0;j<i-1;j++)
		{
			arr[j]=change(arr[j],spacing,i);
			temp-=arr[j];
		}
		arr[i-1]=temp;
	}
}
 