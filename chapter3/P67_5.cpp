//
// Created by 黎圣  on 2023/7/30.
//
#include "iostream"
//50是我举的例子
#define MAX 50
struct stack
{
    int data[MAX];
    int top[2];
};
struct stack s;

//i是选择0号栈还是1号栈，x是入栈的元素
int push(int i, int x)
{
    if (i != 0 && i != 1)
    {
        printf("无栈\n");
        return 0;
    }
    if (s.top[1] - s.top[0] == 1)
    {
        printf("栈满\n");
        return 0;
    }
    if (i == 0)
    {
        s.data[++s.top[0]] = x;
        return 1;
    }
    if (i == 1)
    {
        s.data[--s.top[1]] = x;
        return 1;
    }
}

//i是选择0号栈还是1号栈
int pop(int i)
{
    if (i != 0 && i != 1)
    {
        printf("无栈\n");
        return 0;
    }
    if (i == 0)
    {
        if (s.top[0] == -1)
        {
            printf("0号栈栈空\n");
            return 0;
        }
        return s.data[s.top[0]--];
    }
    else
    {
        if (s.top[1] == MAX)
        {
            printf("1号栈栈空\n");
            return 0;
        }
        return s.data[s.top[1]++];
    }
}
int main()
{
    s.top[0] = -1;
    s.top[1] = MAX;
//    if (push(0, 1) != 0)
//        printf("0号栈入栈成功\n");
//    int x = pop(0);
//    if (x != 0)
//        printf("0号栈出栈成功，出栈元素为%d\n", x);
//    int y = pop(0);
    if (push(1, 1) != 0)
        printf("1号栈入栈成功\n");
    int x = pop(1);
    if (x != 0)
        printf("1号栈出栈成功，出栈元素为%d\n", x);
    int y = pop(1);
    return 0;
}
