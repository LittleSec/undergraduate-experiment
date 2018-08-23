#include<stdio.h>
void main()
{
    int n,m;
    printf("请输入人数和报数n和m：");
    scanf("%d %d",&n,&m);
    void baoshu(int n,int b);
    printf("出列顺序：");    //不需要回车，因为下面0%10==0也会回车一次。
    baoshu(n,m);
}

void baoshu(int n,int b)
{
    int a[n],i,j,m=n,p=0,k=0;
    /*i是a数组的下标，
      j，m用来控制循环次数，
      n用来记录当前数组元素的个数，重新给a数组赋值时需要用，所以它会变，所以不用n控制循环次数，
      p用来记录出列的个数，
      k用来记录应该出列的人的下标。*/
    for(i=0;i<n;i++)
        a[i]=i+1;   //给数组a初始化。
    for(j=0;j<m;j++,n--)
    {
        k+=b-1;     //是b-1，因为数组下标是从0开始的。
        for(;k>=n;k-=n);
        //不能用if，因为有可能k-=n一次后，k还是>=n，所以用for比较好，但是要注意了，不要忘了分号，说明循环体是空的。
        if(p%10==0)     //前面输出提示没有回车，所以p=0时也可以回车。
            printf("\n");
        if(n==1)
            break;
        printf("%-4d",a[k]);
        for(i=k;i<n-1;i++)      //注意是n-1，因为如果是n的话，n+1就越界了。
            a[i]=a[i+1];
        p++;
    }
    if(p%10!=0)     //确定最后是否要换行。
        printf("\n");
    printf("最后留下的人的是原来的第%d号。\n",a[0]);
}
