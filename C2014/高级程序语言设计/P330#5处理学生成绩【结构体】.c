#include<stdio.h>
struct Student
{
    int num;
    char name[20];
    char birthday[11];
    char sex;
    float score1;
    float score2;
    float score3;
    float aver;
}stud[3];

int main()
{
    int i;
    for(i=0;i<3;i++)
    {
        printf("The information of No.%d:\n",i+1);
        printf("Num:");
        scanf("%d",&stud[i].num);
        getchar();
        /*为什么要用getchar：例如，我们输入10101回车，我们希望的结果是：
            Num：10101回车
            Name：He Jiexuan回车
          然而输入10101回车后，系统的缓存区里面有这六个字符，而能与%d匹配的只有10101，
          而剩下的回车不能匹配，会继续留着，如果没有getchar，那么回车就直接与gets匹配，导致如下：
            Num：10101回车
            Name:Birthday:
          所以，但凡遇到数字和字符要连续输入的时候，就要考虑这个问题。
        */
        printf("Name:");
        gets(stud[i].name);
        printf("Birthday:");
        gets(stud[i].birthday);
        printf("Sex:");
        scanf("%c",&stud[i].sex);
        printf("Course1:");
        scanf("%f",&stud[i].score1);
        printf("Course2:");
        scanf("%f",&stud[i].score2);
        printf("Course3:");
        scanf("%f",&stud[i].score3);
        stud[i].aver=(stud[i].score1+stud[i].score2+stud[i].score3)/3;
        printf("\n");
    }
    printf("No. Num    Name                 Birthday   Sex  Cou1   Cou2   Cou3     Aver\n");
    for(i=0;i<3;i++)
        printf("%-2d  %-5d  %-20s %-10s %-2c   %-6.1f %-6.1f %-6.1f %6.2f\n",i+1,stud[1].num,stud[i].name,stud[i].birthday,stud[i].sex,stud[i].score1,stud[i].score2,stud[i].score3,stud[i].aver);
    return 0;
}
