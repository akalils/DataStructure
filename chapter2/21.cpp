//
// Created by 黎圣  on 2023/7/27.
//
#include "iostream"
typedef struct node
{
    int data;
    struct node *next;
}*linklist;
int a[15] = {1,2,3,4,5,6,7,8,9,4,5,6,7,8,9};
int n = 15;
void CreateList(linklist &L)
{
    L = (linklist)malloc(sizeof(struct node));
    struct node *s;
    struct node *r = L;
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
linklist find(linklist L)
{
    struct node *s = L, *f = L;
    while (s != NULL && f->next != NULL)
    {
        s = s->next;
        f = f->next->next;
        if (s->data == f->data) break;
    }
    if (s == NULL || f->next == NULL) return NULL;//不成环
    struct node *p = L, *q = s;
    while (p->data != q->data)
    {
        p = p->next;
        q = q->next;
    }
    return p;
}
int main()
{
    linklist L;
    CreateList(L);
    display(L);
    struct node *ans = find(L);
    printf("%d", ans->data);
    return 0;
}
