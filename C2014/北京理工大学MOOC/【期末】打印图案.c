#include<stdio.h>
void main()
{
    int h1,i,j,h2;
    char start;
    scanf("%c%d",&start,&h1);
    h2=h1;
    for(i=0;i<h1;i++,h2--)
    {
        for(j=h2-1;j>0;j--)
            printf(" ");
        for(j=0;j<2*i+1;j++,start++)
        {
            if(start>'Z')
                start-=26;
            printf("%c",start);
        }
        printf("\n");
    }
}
