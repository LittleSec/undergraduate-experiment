#include<stdio.h>
void main()
{
    int i,j,k,max,maxj,flag;
    int a[3][4]={1,2,3,4,5,6,7,8,9,10,11,12};
    //int a[3][4]={1,2,3,13,5,6,8,7,9,10,11,12};
    for(i=0;i<3;i++)
    {
        for(j=0;j<4;j++)
            printf("%-5d",a[i][j]);
        printf("\n");
    }
    for(i=0;i<3;i++)
    {
        max=a[i][0];
        maxj=0;
        for(j=0;j<4;j++)
            if(a[i][j]>max)
            {
                max=a[i][j];
                maxj=j;
            }
        flag=1;
        for(k=0;k<3;k++)
            if(max>a[k][maxj])
            {
                flag=0;
                break;
            }
        if(flag)
        {
            printf("鞍点为:%d,在第%d行,第%d列\n",max,i+1,maxj+1);
            break;
        }
    }
    if(!flag)
        printf("无鞍点\n");
}
