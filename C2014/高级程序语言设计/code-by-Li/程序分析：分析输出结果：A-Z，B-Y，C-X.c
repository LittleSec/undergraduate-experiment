#include<stdio.h>
void main()
{
    char i,j,k;
    for(i='X';i<='Z';i++)
    {
        if(i=='X')
            continue;
        for(j='X';j<='Z';j++)
        {
            if(j==i)
                continue;
            for(k='X';k<='Z';k++)
            {
                if(k==i||k==j||k=='X'||k=='Z')
                    continue;
                printf("The match is: A--%c, B--%c, C--%c\n",i,j,k);
            }
        }
    }
}
