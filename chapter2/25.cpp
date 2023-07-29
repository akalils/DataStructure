//
// Created by 黎圣  on 2023/7/29.
//
#include "iostream"
typedef struct node
{
    int data;
    struct node *next;
}node, *linklist;
int a[8] = {1,2,3,4,5,6,7,8};
int n = 8;
void CreateList(linklist &L)
{
    L = (linklist)malloc(sizeof(node));
    node *s, *r = L;
    for (int i = 0; i < n; i++)
    {
        s = (linklist)malloc(sizeof(node));
        s->data = a[i];
        r->next = s;
        r = r->next;
    }
    r->next = NULL;
}
void display(linklist L)
{
    node *s = L->next;
    while (s)
    {
        printf("%d ", s->data);
        s = s->next;
    }
    printf("\n");
}
void newlist(linklist &L)
{
    node *p = L, *q = L, *l, *r;
    while (q->next != NULL)
    {
        p = p->next;
        q = q->next;
        if (q->next != NULL) q = q->next;
    }//让p到中点
    //逆置
    q = p->next;
    p->next = NULL;
    while (q)
    {
        r = q->next;
        q->next = p->next;
        p->next = q;
        q = r;
    }
    q = p->next;
    l = L->next;
    p->next = NULL;
    while (q)
    {
        r = q->next;//防止断链
        q->next = l->next;
        l->next = q;
        l = q->next;
        q = r;
    }
}
int main()
{
    linklist L;
    CreateList(L);
    display(L);
    newlist(L);
    display(L);
    return 0;
}
