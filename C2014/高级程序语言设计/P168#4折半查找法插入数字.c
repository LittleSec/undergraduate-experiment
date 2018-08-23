#include <stdio.h>
void main()
{
    int a[10]={2,3,4,5,6,7,8,9,10,12},b,i,j,k;
    int arr[11]={2,3,4,5,6,7,8,9,10,12};
    void Bi_search(int arr[],int n,int x);
    for(i=0;i<10;i++)
        printf("%d ",a[i]);
    printf("\n");
    printf("请输入需要插入的整数：");
    scanf("%d",&b);
    Bi_search(arr,11,b);
    printf("插入一个数后的数组为；");
    for(j=0;j<11;j++)
        printf("%d ",arr[j]);
    printf("\n");
}

void Bi_search(int arr[],int n,int x)
{
    int bot=0,top=n-1,mid=0,k,find=0;
    do
    {
        mid=(top+bot)/2;
        if(arr[mid]==x)
            find=1;
        else if(arr[mid]>x)
            top=mid;
        else
            bot=mid+1;
    }while(find==0&&bot<top);
    if(find==1)
    {
        for(k=10;k>mid-1;k--)
            arr[k+1]=arr[k];
        arr[mid]=x;
    }
    else
    {
        for(k=10;k>mid-1;k--)
            arr[k+1]=arr[k];
        arr[bot]=x;
    }
}
