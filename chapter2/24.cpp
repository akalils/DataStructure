//
// Created by 黎圣  on 2023/7/28.
//
#include "iostream"
typedef struct node
{
    int data;
    struct node *next;
}*linklist;
int a[] = {4,-2,2,-3,-2};
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
void deletesame(linklist L, int n)
{
    struct node *p = L, *f;
    int *q;
    int s = 0;
    q = (int *)malloc(sizeof(int)*(n+1));
    for (int i = 0; i < n; i++)
        *(q + i) = 0;//初始化数组q，里面全放0
    while (p->next != NULL)
    {
        s = abs(p->next->data);
        if (*(q + s) == 0)
        {
            *(q + s) = 1;
            p = p->next;
        }
        else
        {
            //删除结点
            f = p->next;
            p->next = f->next;
            free(f);
        }
    }
    free(q);
}
int main()
{
    linklist L;
    CreateList(L);
    display(L);
    deletesame(L, 5);
    display(L);
    return 0;
}
