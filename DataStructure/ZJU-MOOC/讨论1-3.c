#include<stdio.h>
#include<time.h>
#include<math.h>

#define X 1.1
#define MAXN 100//多项式总共100项
#define REP 10000//重复运行以记录时间，否则太快无法捕捉

double f1(int n,double a[],double x);
double f2(int n,double a[],double x);

int main()
{
    int i;
    double a[MAXN];
    double sum;
    a[0] = 1;
    for(i = 1; i < MAXN; i++)
    {
        a[i]=(double)1/(double)i;
    }

    clock_t start = clock();
    for(i = 0; i < REP; i++)
        sum = f1(MAXN - 1, a, X);
    clock_t stop = clock();
    double du = ((double)stop - (double)start) / CLOCKS_PER_SEC;
    printf("f1(%lf) = %lf\n", X, sum);
    printf("total time = %lf s\n", du);

    start = clock();
    for(i = 0; i < REP; i++)
        sum = f2(MAXN - 1, a, X);
    stop = clock();
    du = ((double)stop - (double)start) / CLOCKS_PER_SEC;
    printf("f2(%lf) = %lf\n", X, sum);
    printf("total time = %lf s\n", du);

    return 0;
}

double f1(int n, double a[], double x)
{
    int i;
    double sum = a[0];
    for(i = 1; i <= n; i++)
        sum += pow(x,i) * a[i];

    return sum;
}

double f2(int n, double a[], double x)
{
    double product = a[n];
    for(; n; n--)
        product = a[n-1] + x * product;

    return product;
}
