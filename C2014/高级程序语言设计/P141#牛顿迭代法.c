#include<stdio.h>
#include<math.h>
void main()
{
    double f1(double);
    double f2(double);
    double a=1.3,b,c,d;
    int n=1;
    printf("方程2x^3-4x^2+3x^2=0的根是：");
    while(n<=1000)
    {
        b=f1(a);
        c=f2(a);
        a=a-(b/c);
        d=f1(a);
        if(fabs(d)<=0.01)
        {
            printf("%lf\n",a);
            break;
        }
        n++;
    }
    if(n>1000)
        printf("%lf\n",a);
}

double f1(double x)
{
    double y;
    y=2*x*x*x-4*x*x+3*x-2;
    return y;
}

double f2(double x)
{
    double y;
    y=6*x*x-8*x+3;
    return y;
}
