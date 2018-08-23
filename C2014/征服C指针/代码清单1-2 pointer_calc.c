#include<stdio.h>
int main()
{
    int hoge;
    int *hoge_p;

    //将指向hoge的指针赋予hoge_p
    hoge_p=&hoge;
    //输出hoge的值
    printf("hoge_p..%p\n",hoge_p);
    //给hoge_p加1
    hoge_p++;
    //输出hoge的值
    printf("hoge_p..%p\n",hoge_p);
    //输出hoge加3后的值
    printf("hoge_p..%p\n",hoge_p+3);

    return 0;
}
