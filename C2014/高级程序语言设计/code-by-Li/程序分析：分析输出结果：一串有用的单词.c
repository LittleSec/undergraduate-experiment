#include "stdio.h"
void main( )
{
    int i;
    char ch;
    char input[ ]= "SSSWILTECH1\1\11W\1WALLMP1";
    for (i=2; (ch=input[i])!='\0'; i++)
    {
        switch(ch)
        {
            case 'a': putchar('i');continue;
            case '1': break;
            case '\1': while((ch=input[++i])!='\1' && ch!='\0');
            case '9': putchar('S');
            case 'E':
            case 'L': continue;
            default: putchar(ch);continue;
        }
        putchar(' ');
    }
    putchar('\n');
}
