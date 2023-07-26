//
// Created by 黎圣  on 2023/7/19.
//
#include "iostream"
struct node
{
    int data;
    struct node *next;
};
struct node *del_min(struct node *L)
{
    struct node *p = L->next;
    struct node *pre = L;
    struct node *p_min = L->next;
    struct node *pre_min = L;
    while (p != NULL)
    {
        if (p->data < p_min->data)
        {
            p_min = p;
            pre_min = pre;
        }
        pre = p;
        p = p->next;
    }
    pre_min->next = p_min->next;
    free(p_min);
    return L;
}