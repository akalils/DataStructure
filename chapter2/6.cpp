//
// Created by 黎圣  on 2023/7/20.
//
#include "iostream"
struct node
{
    int data;
    struct node *next;
};
void bubble_sort(struct node *L)
{
    struct node *pre = L;
    struct node *p = L->next;
    struct node *r;
    int count, flag;
    while (p != NULL)
    {
        count++;
        p = p->next;
    }
    for (int i = 0; i < count; i++)
    {
        flag = 0;
        while (p->next != NULL)
        {
            if (p->data > p->next->data)
            {
                r = p->next->next;
                pre->next = p->next;
                p->next->next = p;
                pre = p->next;
                p->next = r;
                flag = 1;
            }
            else
            {
                pre = p;
                p = p->next;
            }
        }
        if (flag == 0) break;
        pre = L;
        p = L->next;
    }
}