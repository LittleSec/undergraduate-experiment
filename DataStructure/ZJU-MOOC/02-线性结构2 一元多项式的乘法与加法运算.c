//不通过的测试点：系数和指数取上限，结果有零多项式

#include<stdio.h>
#include<stdlib.h>
#define LEN sizeof(ElemType)

typedef struct Poly{
    long coef; //系数
    long expn;   //指数
    struct Poly *next;
}ElemType;

ElemType *LinkList();//建立空链表
void DestroyPolyn(ElemType *p);//销毁一元多项式P
void PrlongPolyn(ElemType *p);//打印输出一元多项式P
ElemType *CreatPolyn(ElemType *head);//输入系数和指数，建立表示一元多项式的有序链表P
ElemType *ListInsert_L(ElemType *head, ElemType *e);//处理并插入元素e
ElemType *MultiplyPolyn(ElemType *Pa, ElemType *Pb);//相乘
ElemType *AddplyPolyn(ElemType *Pa, ElemType *Pb);//相加

ElemType *LinkList(){
    ElemType *head;
    head = NULL;
    return head;
};

void DestroyPolyn(ElemType *p){//销毁一元多项式P
    ElemType *q;

    if(!p)//空表就不用销毁了
        exit(0);

    while(p->next){
        q = p->next;
        p->next = q->next;
        free(q);
    }//while

    if(! p->next)//删除头结点
        free(p);
}//DestroyPolyn

void PrlongPolyn(ElemType *p){//打印输出一元多项式P
    long flag = 0;	/*辅助调整输出格式用*/
	if (!p){
		printf("0 0\n");
		return;
	}
	while (p){
		if (!flag)
			flag = 1;
		else
			printf(" ");
		printf("%ld %ld", p->coef, p->expn);
		p = p->next;
	}
	printf("\n");
}//PrlongPolyn

ElemType *CreatPolyn(ElemType *head){
    //输入系数和指数，建立表示一元多项式的有序链表P
    int N;
    scanf("%d", &N);
    ElemType *p1;
    while(N--){
        p1 = (ElemType*)malloc(LEN);
        scanf("%ld %ld",&p1->coef, &p1->expn);
        head = ListInsert_L(head, p1);
    }//while
    return head;
}//CreatPolyn

ElemType *ListInsert_L(ElemType *head, ElemType *e){
    //处理并插入元素e
    ElemType *p0, *p1, *p2;
	p1 = head;
	p0 = e;

    if(head == NULL){
		head = p0;
		p0->next = NULL;
	}//if
	else{
        while((p0->expn < p1->expn) && (p1->next!=NULL)){//寻找要插入的地方。降序
            p2 = p1;//p2指向的是比插入结点小的结点。
            p1 = p1->next;//p1指向的是比插入结点大的结点。综上：p2>p0>p1。
        }//while

        if(p0->expn > p1->expn){
            if(head == p1)//要插入的地方是开头。
                head = p0;
            else
                p2->next = p0;
            p0->next=p1;
        }//if
        else if(p0->expn == p1->expn){
            p1->coef += p0->coef;
            if(p1->coef == 0){//系数为0，删除结点
                p2->next = p1->next;
                free(p1);
            }//if
        }//else if
        else{//要插入的地方是结尾。
            p1->next = p0;
            p0->next = NULL;
        }
	}//else

    return head;
}//ListInsert_L

ElemType *MultiplyPolyn(ElemType *Pa, ElemType *Pb){
    //多项式乘法：Pc = Pa * Pb
    ElemType *ha,*hb,*qa,*qb,*Pc,*c;//qa指向Pa中的当前结点，qb同理
    long ccoef;
    long cexpn;
    ha = Pa;
    hb = Pb;

    if(!Pa || !Pb)
        return NULL;
    Pc = LinkList();
    for(qa = ha; qa; qa = qa->next){//当qa非空，逐个检索qa
        for(qb = hb; qb; qb = qb->next){
            ccoef = qa->coef * qb->coef;
            cexpn = qa->expn + qb->expn;
            if(ccoef != 0){
                c = (ElemType*)malloc(LEN);
                c->coef = ccoef;
                c->expn = cexpn;
                Pc = ListInsert_L(Pc, c);
            }
        }//for(qb)
    }//for(qa)

    return Pc;
}//MultiplyPolyn

ElemType *AddplyPolyn(ElemType *Pa, ElemType *Pb)
{	//多项式加法
    ElemType *ha,*hb,*qa,*qb,*Pc,*c;//qa指向Pa中的当前结点，qb同理
    long ccoef;
    long cexpn;
    //qa = ha = Pa;
    //qb = hb = Pb;

    if(!Pa && Pb)
        return Pb;
    else if(!Pb && Pa)
        return Pa;
    else if(!Pa && !Pb)
        return NULL;

    Pc = LinkList();

    //不能直接Pc = ListInsert_L(Pc, qa);
    for(qa = Pa; qa; qa = qa->next){
        ccoef = qa->coef;
        cexpn = qa->expn;
        c = (ElemType*)malloc(LEN);
        c->coef = ccoef;
        c->expn = cexpn;
        Pc = ListInsert_L(Pc, c);
    }

    for(qb = Pb; qb; qb = qb->next){
        ccoef = qb->coef;
        cexpn = qb->expn;
        c = (ElemType*)malloc(LEN);
        c->coef = ccoef;
        c->expn = cexpn;
        Pc = ListInsert_L(Pc, c);
    }

    return Pc;
}

long main(){
    ElemType *Pa,*Pb,*Pc,*Pd;

    Pa = LinkList();
    Pa = CreatPolyn(Pa);

    Pb = LinkList();
    Pb = CreatPolyn(Pb);

    Pc = MultiplyPolyn(Pa, Pb);
    PrlongPolyn(Pc);

    Pd = AddplyPolyn(Pa, Pb);
    PrlongPolyn(Pd);

    DestroyPolyn(Pa);
    DestroyPolyn(Pb);
    DestroyPolyn(Pc);
    DestroyPolyn(Pd);

    return 0;
}
