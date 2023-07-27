//
// Created by 黎圣  on 2023/7/27.
//
#include "iostream"
typedef struct node
{
    int data;
    struct node *next;
}*linklist;
int a[5] = {5,4,3,2,1};
int n = 5;
void CreateList(linklist &L)
{
    L = (linklist)malloc(sizeof(struct node));
    struct node *s, *r = L;
    for (int i = 0; i < n; i++)
    {
        s = (linklist)malloc(sizeof(struct node));
        s->data = a[i];
        r->next = s;
        r = r->next;
    }
    s->next = NULL;
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
int findk(linklist L, int k)
{
    struct node *p = L->next, *q = L->next;
    int num = 0;
    while (p)
    {
        if (num < k) num++;
        else if (num == k) q = q->next;
        p = p->next;
    }
    if (num < k) return 0;//不可能
    else
    {
        printf("%d ", q->data);
        return 1;
    }
}
int main()
{
    linklist L;
    CreateList(L);
    display(L);
    findk(L, 2);
}
