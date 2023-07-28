//
// Created by 黎圣  on 2023/7/28.
//
#include "iostream"

using namespace std;
typedef struct node
{
    char data;
    struct node *next;
} *linklist;
char a[7] = {'l','o','a','d','i','n','g'};
char b[5] = {'b','e','i','n','g'};
int n = 7;
int m = 5;
void CreateList1(linklist &L)
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
void CreateList2(linklist &L)
{
    L = (linklist)malloc(sizeof(struct node));
    struct node *s, *r = L;
    for (int i = 0; i < m; i++)
    {
        s = (linklist)malloc(sizeof(struct node));
        s->data = b[i];
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
        printf("%c ", s->data);
        s = s->next;
    }
    printf("\n");
}
int length(linklist L)
{
    int count = 0;
    struct node *p = L->next;
    while (p)
    {
        count++;
        p = p->next;
    }
    return count;
}
linklist first(linklist L1, linklist L2)
{
    struct node *p1 = L1->next, *p2 = L2->next;
    int len1 = length(L1);
    int len2 = length(L2);
    int dist = abs(len1 - len2);
    if (len1 >= len2)
        while (dist--)
            p1 = p1->next;
    else
        while (dist--)
            p2 = p2->next;
    while (p1)
    {
        if (p1->data != p2->data)
        {
            p1 = p1->next;
            p2 = p2->next;
        }
        else
            return p1;
    }
    return p1;
}
int main()
{
    linklist L1, L2;
    CreateList1(L1);
    CreateList2(L2);
    display(L1);
    display(L2);
    linklist ans = first(L1, L2);
    printf("%c", ans->data);
    return 0;
}
