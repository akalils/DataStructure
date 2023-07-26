//
// Created by 黎圣  on 2023/7/19.
//
#include <iostream>
struct node
{
    int data;
    struct node *next;
};
struct node *del_x(struct node *L, int x)
{
    struct node *p;
    if (L == NULL) return NULL;
    if (L->data == x)
    {
        p = L;
        L = L->next;
        free(p);
        return del_x(L, x);
    }
    else
    {
        L->next = del_x(L->next, x);
        return L;
    }
}