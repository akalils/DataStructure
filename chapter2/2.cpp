//
// Created by 黎圣  on 2023/7/19.
//
#include "iostream"
struct node
{
    int data;
    struct node *next;
};
void *di2ti(struct node *L, int x)
{
    struct node *p = L->next;
    struct node *pre = L;
    struct node *q;
    while (p != NULL)
    {
        if (p->data == x)
        {
            q = p;
            pre->next = p->next;
            p = p->next;
            free(q);
        }
        else
        {
            pre = p;
            p = p->next;
        }
    }
}
