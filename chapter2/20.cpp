//
// Created by 黎圣  on 2023/7/26.
//
#include "iostream"
typedef struct node
{
    int data, f;
    struct node *next, *prior;
}*linklist, lnode;
int a[5] = {1,2,3,4,5};
int n = 5;
void CreateTowaylist(linklist &L)
{
    L = (linklist)malloc(sizeof(struct node));
    struct node *s;
    struct node *r = L;
    L->prior = NULL;
    L->next = L;
    for (int i = 0; i < n; i++)
    {
        s = (linklist)malloc(sizeof(struct node));
        s->data = a[i];
        s->f = 0;
        s->next = r->next;
        r->next->prior = s;
        r->next = s;
        s->prior = r;
        r = s;
    }
    r->next = NULL;
}
void display(linklist L)
{
    struct node *s = L->next;
    while (s)
    {
        printf("%d ", s->data);
        s = s->next;
    }
    printf("\n");
}
linklist Locate(linklist &L, int x)
{
    struct node *q, *p = L->next;
    while (p&& p->data != x)
        p = p->next;
    if (!p) printf("x不存在");
    else
    {
        p->f++;
        //双向链表删除结点
        if (p->next != NULL) p->next->prior = p->prior;//如果此时p是链表中最后一个值的话就可以不用做这一步了
        p->prior->next = p->next;
        q = p->prior;
        while (q != L && q->f <= p->f) q = q->prior;//让q去找适合p结点插入的地方
        //双向链表插入结点
        p->next = q->next;
        q->next->prior = p;
        p->prior = q;
        q->next = p;
    }
    return p;
}
int main()
{
    linklist L;
    CreateTowaylist(L);
    display(L);
    Locate(L, 3);
    display(L);
    return 0;
}