//
// Created by 黎圣  on 2023/7/19.
//
#include "iostream"
struct node
{
    int data;
    struct node *next;
};
void print_(struct node *L)
{
    if (L == NULL)
        return;
    print_(L->next);

    printf("%d ", L->data);
}