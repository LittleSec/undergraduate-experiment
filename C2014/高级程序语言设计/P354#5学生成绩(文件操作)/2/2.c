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

void read(struct Student stud[])
{
    int i;
    FILE *fp1;
    if((fp1=fopen("student.dat","wb"))==NULL)
    {
        printf("cannot open file\n");
        return;
    }
    for(i=0;i<N;i++)
        if(fwrite(&stud[i],sizeof(struct Student),1,fp1)!=1)
            printf("file write error\n");
    fclose(fp1);
}

void write_to_f1(struct Student stud[])
{
    FILE *fp1;
    int i;
    if((fp1=fopen("student.dat","rb"))==NULL)
    {
        printf("cannot open file\n");
        return;
    }
    for(i=0;i<N;i++)
        if(fread(&stud[i],sizeof(struct Student),1,fp1)!=1)
        {
            if(feof(fp1))
            {
                fclose(fp1);
                return;
            }
            printf("file read error\n");
        }
    fclose(fp1);
}

void read_and_sort(struct Student stud[])
{
    int i,j,k;
    struct Student temp;
    FILE *fp2;
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
    if((fp2=fopen("sort.dat","w"))==NULL)
    {
        printf("cannot open file\n");
        return;
    }
    for(i=0;i<N;i++)
    {
        fprintf(fp2,"%-2d %-6d ",i+1,stud[i].num);
        fprintf(fp2,"%-20s ",stud[i].name);
        fprintf(fp2,"%-2c ",stud[i].sex);
        for(j=0;j<3;j++)
            fprintf(fp2,"%-6.1f ",stud[i].score[j]);
        fprintf(fp2,"%6.2f\n",stud[i].aver);
    }
    fclose(fp2);
}

void write_to_f2(struct Student stud[])
{
    FILE *fp2;
    int i;
    if((fp2=fopen("sort.dat","r"))==NULL)
    {
        printf("cannot open file\n");
        return;
    }
    for(i=0;i<N;i++)
        if(fread(&stud[i],sizeof(struct Student),1,fp2)!=1)
        {
            if(feof(fp2))
            {
                fclose(fp2);
                return;
            }
            printf("file read error\n");
        }
    fclose(fp2);
}

int main()
{
    int i,j;
    //struct Student stud[N];
    struct Student stud[N]={{10101,"He Jiexuan",'M',{100,100,100}},{10102,"Tang Maru",'F',{78.5,66.5,80.5}},{10103,"Wang Nima",'M',{9,99,100}},{10104,"Zhang Quandan",'F',{89.5,59,100}},{10105,"Tong Tong",'M',{77,63,99}}};
    for(i=0;i<N;i++)
    {/*
        printf("The information of No.%d:\n",i+1);
        printf("Num:");
        scanf("%d",&stud[i].num);
        getchar();
        printf("Name:");
        gets(stud[i].name);
        printf("Sex:");
        scanf("%c",&stud[i].sex);
        for(j=0;j<3;j++)
        {
            printf("Course%d:",j+1);
            scanf("%f",&stud[i].score[j]);
        }*/
        stud[i].aver=(stud[i].score[0]+stud[i].score[1]+stud[i].score[2])/3;
        //printf("\n");
    }
    read(stud);
    write_to_f1(stud);
    read_and_sort(stud);
    write_to_f2(stud);
    return 0;
}


