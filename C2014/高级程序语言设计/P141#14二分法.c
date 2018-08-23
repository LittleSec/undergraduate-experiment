#include<stdio.h>
#include<math.h>
void main()
{
    double f(double x);
    double a=-10,b=10,c,m;
    int n=1;
    printf("方程2x^3-4x^2+3x^2=0的根是：");
    while(n<=1000)
    {
        c=(a+b)/2;
        m=f(c);
        if(fabs(m)<=0.01)
        {
            printf("%lf\n",c);
            break;
        }
        else if(m>0)
            b=c;
        else
            a=c;
        n++;
    }
    if(n>1000)
        printf("%lf\n",c);
    return 0;
}

double f(double x)
{
    double y;
    y=2*x*x*x-4*x*x+3*x-2;
    return y;
}
