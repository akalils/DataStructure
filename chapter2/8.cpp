//
// Created by 黎圣  on 2023/7/20.
//
#include "iostream"
struct node
{
    int data;
    struct node *next;
};
struct node *FindCommonNodes_1(struct node *L1, struct node *L2)
{
    struct node *p1 = L1;
    struct node *p2 = L2;
    while (p1 != NULL)
    {
        p2 = L2;
        while (p2 != NULL)
        {
            if (p1 == p2)
                return p1;
            p2 = p2->next;
        }
        p1 = p1->next;
    }
}
struct node *FindCommonNodes_2(struct node *L1, struct node *L2)
{
    int num1 = 0;
    int num2 = 0;
    struct node *p1 = L1;
    struct node *p2 = L2;
    while (p1 != NULL)
    {
        num1++;
        p1 = p1->next;
    }
    while (p2 != NULL)
    {
        num2++;
        p2 = p2->next;
    }
    if (num1 > num2)
    {
        int temp = num1 - num2;
        p1 = L1;
        for (int i = 0; i < temp; i++)
        {
            p1 = p1->next;
        }
    }
    else
    {
        int temp = num2 - num1;
        p2 = L2;
        for (int i = 0; i < temp; i++)
        {
            p2 = p2->next;
        }
    }
    while (p1 != NULL)
    {
        if (p1 == p2)
            return p1;
        p1 = p1->next;
        p2 = p2->next;
    }
    return NULL;
}