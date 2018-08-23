#include<stdio.h>
#include<stdlib.h>

typedef struct Ptr{
    long address;
    int data;
    long next_address;
    struct Ptr *next;
}Ptr;

//创建链表
Ptr *CreatList(Ptr *head, long N){
    Ptr *p, *q, *now;
    p = head;

    //形成链表，注意此时的链表是没有结束的NULL的
    long address;
    int data;
    long next_address;
    int n = N;
    while(n--){
        Ptr *node = (Ptr*)malloc(sizeof(Ptr));
        scanf("%ld %d %ld",&address, &data, &next_address);
        node->address = address;
        node->data = data;
        node->next_address = next_address;
        node->next = NULL;
        p->next = node;
        p = node;
    }

    //形成真正的链表
    //q是当前要更改的点，p在q前，now指示当前插入的位置
    now = head;
    int i = N, j;
    while(i--){
        p = now;
        q = p->next;
        for(j = 0; j < i; j++){
            if(now->next_address == q->address)
                break;
            else{
                p = q;
                q = q->next;
            }
        }
        p->next = q->next;
        q->next = now->next;
        now->next = q;
        now = now->next;
    }
    now->next = NULL;

    return head;
}//CreatList

//倒置链表
Ptr *ReverseList(Ptr *head, long K){
    int cnt = 1;
    Ptr *new, *old, *temp;
    new = head->next;
    old = new->next;
    while(cnt < K){
        temp = old->next;
        old->next = new;
        old->next_address = new->address;
        new = old;
        old = temp;
        cnt++;
    }
    head->next->next = old;
    head->next->next_address = old->address;
    head->next = new;
    head->next_address = new->address;

    return head;
}//ReversList

//打印链表
void PrintList(Ptr *head){
    Ptr *p = head->next;
    int i;
    for(i = 0; i < head->data - 1; p = p->next, i++)
        printf("%05ld %ld %05ld\n", p->address, p->data, p->next_address);
    printf("%05ld %ld %ld\n", p->address, p->data, p->next_address);
}//PrintList

int main(){
    long first_address, N, K;
    scanf("%ld %ld %ld", &first_address, &N, &K);
    Ptr *head = (Ptr*)malloc(sizeof(Ptr));
    head->address = first_address;
    head->data = N;
    head->next_address = first_address;
    head->next = NULL;
    head = CreatList(head, N);
    head = ReverseList(head, K);
    printf("\n");
    PrintList(head);
    return 0;
}
