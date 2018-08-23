//具体问题：实验室电脑中，用codeblocks（10.05版）执行，若删除的节点在链表中存在则只能删除一次。
//在该改良程序中，把main函数的循环改成了do……while型。在实验室下的VC++和codeblocks结果均正确。
#include<stdio.h>
#include<stdlib.h>
#include<math.h>
#define LEN sizeof(struct student)
struct student
{
    long num;
    float score;
    struct student *next;
};

int n;      //定义n为全局变量，因为n的值几乎所有函数都要更改。

struct student *insert(struct student *head,struct student *stud)
{
	struct student *p0,*p1,*p2;
	p1=head;
	p0=stud;
	if(head==NULL)
    {
		head=p0;
		p0->next=NULL;
	}
	else
	{
		while((p0->num>p1->num)&&(p1->next!=NULL))//寻找要插入的地方。
		{
			p2=p1;//p2指向的是比插入结点小的结点。
			p1=p1->next;//p1指向的是比插入结点大的结点。综上：p2<p0<p1。
		}
		if(p0->num<p1->num)
		{
			if(head==p1)//要插入的地方是开头。
				head=p0;
			else
				p2->next=p0;
			p0->next=p1;
		}
		else//要插入的地方是结尾。
		{
			p1->next=p0;
			p0->next=NULL;
		}
	}
	n=n+1;
	return(head);
}

struct student *creat(void)
{
    struct student *head,*p,*p1;
    n=0;
    p=(struct student*)malloc(LEN);
    p1=(struct student*)malloc(LEN);
    scanf("%ld,%f",&p->num,&p->score);
    if(p->num==0)
    {
        head=NULL;
        return head;
    }
    else
    {
        head=p;
        n++;
    }
    p->next=NULL;
    while(p1->num!=0)
    {
        scanf("%ld,%f",&p1->num,&p1->score);
        if(p1->num!=0)
        {
            head=insert(head,p1);
            p1=(struct student*)malloc(LEN);
        }
    }
    return head;
}

struct student *del(struct student *head,long num)
{
	struct student *p1,*p2;
    if (head==NULL)
	{
		printf("\nList is null!\n");
        return (head);
	}
    p1=head;
    while(num!=p1->num&&p1->next!=NULL)
    {
		p2=p1;//p2最终指向要删去的前一个结点。
		p1=p1->next;//p1最终指向要删去的。
	}
	if(num==p1->num)
    {
		if(p1==head)
			head=p1->next;
		else
			p2->next=p1->next;
		printf("delete:%ld\n",num);
		n=n-1;
		free(p1);
	}
	else
		printf("%ld not been found!\n",num);
	return(head);
 }

void print(struct student *head)
{
    struct student *p;
    if(head!=NULL)
    {
        printf("\nNow, These %d records are:\n",n);
        for(p=head;p!=NULL;p=p->next)
            printf("%5ld %5.1f\n",p->num,p->score);
    }
    else
        printf("\nSorry, No records!\n");
}

int main()
{
    struct student *head,*dela,*add;

    printf("Input record:(0,0 for exit)\n");
    head=creat();
    print(head);
    do
    {
        dela=(struct student*)malloc(LEN);
        printf("\nInput the num you want to delate:(0 for exit)");
        scanf("%ld",&dela->num);
        if(dela->num!=0)
        {
            head=del(head,dela->num);
            print(head);
        }
    }while(dela->num!=0);
    do
    {
        add=(struct student*)malloc(LEN);
        printf("\nInput the record you want to insert:(0,0 for exit)");
        scanf("%ld,%f",&add->num,&add->score);
        if(add->num!=0)
        {
            head=insert(head,add);
            add=(struct student*)malloc(LEN);
            print(head);
        }
    }while(add->num!=0);
    return 0;
}
