#include<stdio.h>
void main()
{
    int x,y,i,j,k,max,maxj,flag;
    int a[20][20];
    scanf("%d %d",&x,&y);
    for(i=0;i<x;i++)
        for(j=0;j<y;j++)
            scanf("%d",&a[i][j]);
    for(i=0;i<x;i++)
    {
        max=a[i][0];
        maxj=0;
        for(j=0;j<y;j++)
            if(a[i][j]>max)
            {
                max=a[i][j];
                maxj=j;
            }
        flag=1;
        for(k=0;k<x;k++)
            if(max>a[k][maxj])
            {
                flag=0;
                break;
            }
        if(flag)
        {
            printf("Point:a[%d][%d]==%d\n",i,maxj,max);
            break;
        }
    }
    if(!flag)
        printf("No Point\n");
}
