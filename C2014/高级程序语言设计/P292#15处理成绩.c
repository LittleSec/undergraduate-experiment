#include<stdio.h>
void main()
{
    int i;
    char num[4][16]={"400020081618001","400020081618002","400020081618003","400020081618004"};
    //不能用花括号，不然会隐形溢出，以为char型数字会转化成ASCII码，用双引号代表这是字符串。
    float score[4][6]={{88,70,91,59.5,30},{88,70,91,30,70},{85,85,85,85,85},{85,84,99,99,99}};
    //float score[4][6]={{88,70,91,59.5,30},{88,20,91,30,70},{85,85,85,85,85},{85,84,99,99,99}};
    //float score[4][6]={{85,70,91,59.5,30},{88,20,91,30,70},{89,85,85,85,85},{80,84,99,99,99}};
    void fail2(float (*a)[6],char (*b)[16]);
    void succeed(float (*a)[6],char (*b)[16]);
    printf("两门及两门以上课程不及格的学生有：\n");
    fail2(score,num);
    for(i=0;i<80;i++)
        printf("=");
    //分割线
    printf("平均成绩在90以上或全部课程在85分以上的学生有：\n");
    succeed(score,num);
}

float average(float a[][6],int n)
{
    int i;
    float sum=0;
    //sum不要忘了是float型，不然返回值会不准确。
    for(i=0;i<5;i++)
        sum=sum+a[n][i];
    return sum/i;
}

void fail2(float (*a)[6],char (*b)[16])
{
    int times,j,i;
    for(j=0;j<4;j++)
        for(times=0,i=0;i<5||times==2;i++)
        {
            if(*(*(a+j)+i)<60)
                times++;
            if(times==2)
            {
                printf("学号为：%s\n",b+j);
                printf("\t他的全部课程成绩：");
                    for(i=0;i<5;i++)
                        printf("%-7.2f",*(*(a+j)+i));
                printf("\n\t他的平均分为：%.2f\n",average(a,j));
                break;
            }
        }
}

void succeed(float (*a)[6],char (*b)[16])
{
    int flag,i,j;
    for(j=0;j<4;j++)
    {
        flag=1;
        for(i=0;i<5;i++)
            if(*(*(a+j)+i)<85)
                flag=0;
        if(flag||(average(a,j)>=90))
        {
            printf("学号为：%s\n",b+j);
            printf("\t他的全部课程成绩：");
                for(i=0;i<5;i++)
                    printf("%-7.2f",*(*(a+j)+i));
            printf("\n\t他的平均分为：%.2f\n",average(a,j));
        }
    }
}
