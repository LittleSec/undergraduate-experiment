#include <stdio.h>
#include <stdlib.h>
void process(int b[10][10],int m)
{
    int i,j,k;
    i=0,j=m/2;
    b[i][j]=1;
    for(k=2;k<=m*m;k++)
    {
        i--;j++;
        if((i<0)&&(j>=m))
        {
            i+=2;
            j--;
        }
        if(i<0)
            i=m-1;
        if(j>=m)
            j=0;
        if(b[i][j]!=0)
        {
            i+=2;
            j--;
        }
        b[i][j]=k;
    }
}

void main()
{
    int i,j,n;
    static int a[10][10];
    printf("Input n:");
    scanf("%d",&n);
    if (n%2==0)
	{
	    printf("%d*%d matrix is illegal.\n",n,n);
        exit(0);
	}
    else
        process(a,n);
    for(i=0;i<n;i++)
    {
        for(j=0;j<n;j++)
        printf("%3d",a[i][j]);
        printf("\n");
    }
}
