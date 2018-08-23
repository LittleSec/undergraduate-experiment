#include<stdio.h>
#include<stdlib.h>
#define N 5
struct Student
{
    int num;
    char name[20];
    char sex;
    float score[3];
    float aver;
};

struct Student *read(struct Student stud[N])
{
    int i,j,sum;
    FILE *fp1;
    if((fp1=fopen("student.dat","wb"))==NULL)
    {
        printf("cannot open file\n");
        return;
    }
    for(i=0;i<N;i++)
    {
        printf("The information of No.%d:\n",i+1);
        printf("Num:");
        scanf("%d",&stud[i].num);
        getchar();
        printf("Name:");
        gets(stud[i].name);
        printf("Sex:");
        scanf("%c",&stud[i].sex);
        for(j=0,sum=0;j<3;j++)
        {
            printf("Course%d:",j+1);
            scanf("%f",&stud[i].score[j]);
            sum=sum+stud[i].score[j];
        }
        stud[i].aver=sum/3;
        printf("\n");
    }
    for(i=0;i<N;i++)
        if(fwrite(stud+i,sizeof(struct Student),1,fp1)!=1)
            printf("file write error\n");
    fclose(fp1);
    return stud;
}

void write_to_f1(struct Student *stud)
{
    FILE *fp;
    int i;
    if((fp=fopen("student.dat","rb"))==NULL)
    {
        printf("cannot open file\n");
        exit(0);
    }
    for(i=0;i<N;i++)
    {
        fread(stud+i,sizeof(struct Student),1,fp);
        printf("%-2d %-5d %-20s %-2c %-6.1f %-6.1f %-6.1f %6.2f\n",i+1,stud[i].num,stud[i].name,stud[i].sex,stud[i].score[0],stud[i].score[1],stud[i].score[2],stud[i].aver);
    }
    fclose(fp);
}

struct Student *read_and_sort(struct Student stud[N])
{
    int i,j,k;
    struct Student *temp,*p=stud;
    FILE *fp2,*fp1;
    if((fp2=fopen("sort.dat","w"))==NULL)
    {
        printf("cannot open file\n");
        return;
    }
    fp1=fopen("student.dat","rb");
    fread(p,sizeof(struct Student),N,fp1);
    for(i=0;i<N-1;i++)
    {
        k=i;
        for(j=i+1;j<N;j++)
            if(stud[j].aver>stud[k].aver)
                k=j;
        temp=stud[k];
        stud[k]=stud[i];
        stud[i]=temp;
    }
    for(i=0;i<N;i++)
        fprintf(fp2,"%-2d %-5d %-20s %-2c %-6.1f %-6.1f %-6.1f %6.2f\n",i+1,stud[i].num,stud[i].name,stud[i].sex,stud[i].score[0],stud[i].score[1],stud[i].score[2],stud[i].aver);
    fclose(fp2);
    return stud;
}

void write_to_f2()
{
    FILE *fp;
    int i;
    struct Student stud[N];
    if((fp=fopen("sort.dat","r"))==NULL)
    {
        printf("cannot open file\n");
        exit(0);
    }
    for(i=0;i<N;i++)
    {
        fread(&stud[i],sizeof(struct Student),1,fp);
        printf("%-2d %-5d %-20s %-2c %-6.1f %-6.1f %-6.1f %6.2f",i+1,stud[i].num,stud[i].name,stud[i].sex,stud[i].score[0],stud[i].score[1],stud[i].score[2],stud[i].aver);
    }
    fclose(fp);
}


int main()
{
    struct Student stud[N],*p=stud;
    p=read(p);
    write_to_f1(p);
    p=read_and_sort(p);
    write_to_f2();
    return 0;
}


