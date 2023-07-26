//
// Created by 黎圣  on 2023/7/19.
//
#include "iostream"
struct node
{
    int data;
    struct node *next;
};
struct node *del_xy(struct node *L, int x, int y)
{
    struct node *p = L->next;
    struct node *pre = L;
    while(p != NULL)
    {
        if (p->data > x && p->data < y)
        {
            pre->next = p->next;
            free(p);
            p = pre->next;
        }
        else
        {
            pre = p;
            p = p->next;
        }
    }
    return L;
}