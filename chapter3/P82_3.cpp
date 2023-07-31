//
// Created by 黎圣  on 2023/7/31.
//
#include "iostream"
#define MAX 10
struct Stack
{
    int data[MAX];
    int top;
};
bool StackEmpty(Stack s)
{
    if (s.top == -1)
        return true;
    return false;
}
bool StackOverflow(Stack s)
{
    if (s.top == MAX - 1)
        return true;
    return false;
}
bool Push(Stack &s, int x)
{
    if (StackOverflow(s) == true)
        return false;
    s.data[++s.top] = x;
    return true;
}
bool Pop(Stack &s, int &x)
{
    if (StackEmpty(s) == true)
        return false;
    x = s.data[s.top--];
    return false;
}
void DisplayStack(Stack s)
{
    int top1 = s.top;
    while (top1 != -1)
    {
        printf("%d ", s.data[top1--]);
    }
    printf("\n");
}
int EnQueue(Stack &s1, Stack &s2, int x)
{
    if (StackEmpty(s1))
    {
        Push(s1, x);
    }
    else if (StackOverflow(s1) && !StackEmpty(s2))
    {
        printf("队满，入队失败\n");
        return -1;
    }
    if (StackOverflow(s1) && StackEmpty(s2))
    {
        while (!StackEmpty(s1))
        {
            Pop(s1, x);
            Push(s2, x);
        }
    }
    Push(s1, x);
    return 1;
}
void DeQueue(Stack &s1, Stack &s2, int &x)
{
    if (!StackEmpty(s2))
        Pop(s2, x);
    else if (StackEmpty(s1) && StackEmpty(s2))
        printf("队空，出队失败\n");
    else if (!StackEmpty(s1) && StackEmpty(s2))//s1不空，s2为空
    {
        while (!StackEmpty(s1))
        {
            Pop(s1, x);
            Push(s2, x);
        }
        Pop(s2,x);
    }
}
bool QueueEmpty(Stack s1, Stack s2)
{
    if (StackEmpty(s1) && StackEmpty(s2))
        return true;
    else
        return false;
}
int main()
{
    Stack s1, s2;
    s1.top = -1;
    s2.top = -1;
    for (int i = 0; i < MAX; i++)
        Push(s1, i);
    printf("s1:\n");
    DisplayStack(s1);
    int x = 0;
    DeQueue(s1, s2, x);
    printf("出队元素为%d\n", x);
    DisplayStack(s2);
    return 0;
}
