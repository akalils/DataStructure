//
// Created by 黎圣  on 2023/7/29.
//
#include "iostream"
typedef struct node
{
    int data;
    struct node *next;
}*linklist;
void CreateList(linklist &L, char a[],int n)
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
        printf("%c ", s->data);
        s = s->next;
    }
    printf("\n");
}
bool isOK(linklist &L, int n)
{
    char str[n/2];
    int i;
    struct node *p = L->next;
    for (i = 0; i < n/2; i++)
    {
        str[i] = p->data;
        p = p->next;
    }
    i--;
    if (n%2 != 0) p = p->next;//奇数
    while (p && p->data == str[i])
    {
        i--;
        p = p->next;
    }
    if (i == -1) return true;
    return false;
}
int main()
{
    linklist L;
    char a[] = {'a','b','c','b','a'};
    CreateList(L, a, 5);
    display(L);
    if (isOK(L, 5) == true) printf("true");
    else printf("false");
    return 0;
}
