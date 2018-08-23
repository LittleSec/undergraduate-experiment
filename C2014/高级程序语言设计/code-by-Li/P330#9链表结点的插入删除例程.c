#include <stdio.h>
#include <malloc.h>
#define LEN sizeof(struct student)
struct student
{
	long num;
	float score;
	struct student *next;
};
int n;



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
		while((p0->num>p1->num) && (p1->next!=NULL))
		{
			p2=p1;
			p1=p1->next;
		}
		if(p0->num<=p1->num)
		{
			if(head==p1) 
				head=p0;
			else
				p2->next=p0;
			p0->next=p1;
		}
		else
		{
			p1->next=p0;
			p0->next=NULL;
		}
	}
	n=n+1;
	return(head);
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
	while(num!=p1->num && p1->next!=NULL) 
	{ 
		p2=p1;
		p1=p1->next;
	}
	if(num==p1->num) 
	{  
		if(p1==head)
			head=p1->next;
		else
			p2->next=p1->next;
		printf("delete£º%ld\n",num);
		n=n-1;
		free(p1);
	}
	else
		printf("%ld not been found!\n",num); 
	return(head);
}

