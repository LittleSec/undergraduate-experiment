#include<stdio.h>
void main()
{
    char a[100],b[100],c[200];
    char place;
    int i,j,k;
    gets(a);
    gets(b);
    scanf("%c",&place);
    for(k=0,i=0;a[i]!='\0';k++,i++)
    {
        c[k]=a[i];
        if(a[i]==place)
        {
            for(k+=1,j=0;b[j]!='\0';j++,k++)
                c[k]=b[j];
            for(i+=1;a[i]!='\0';i++,k++)
                c[k]=a[i];
            break;
        }
    }
    if(k==i)
        for(j=0;b[j]!='\0';j++,k++)
            c[k]=b[j];
    c[k]='\0';
    puts(c);
}
