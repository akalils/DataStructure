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
struct Queue
{
    int data[MAX];
    int f, r, tag;
};
int EnQueue(Queue &q, int x)
{
    if (q.f == q.r && q.tag == 1)
    {
        printf("队满，入队失败\n");
        return -1;
    }
    q.data[q.r] = x;
    q.r = (q.r + 1) % MAX;
    q.tag = 1;
    return 1;
}
int DeQueue(Queue &q, int &x)
{
    if (q.f == q.r && q.tag == 0)
    {
        printf("队空，出队失败\n");
        return -1;
    }
    x = q.data[q.f];
    q.f = (q.f + 1) % MAX;
    q.tag = 0;
    return 1;
}
int EnStack(Stack &s, int x)
{
    if (s.top == MAX - 1)
    {
        printf("栈满，入栈失败\n");
        return -1;
    }
    s.data[++s.top] = x;
    return 1;
}
int DeStack(Stack &s, int &x)
{
    if (s.top == -1)
    {
        printf("栈空，出栈失败\n");
        return -1;
    }
    x = s.data[s.top--];
    return 1;
}
void display(Queue q)
{
    for (int i = 0; i < MAX; i++)
    {
        printf("%d ", q.data[q.f]);
        q.f = (q.f + 1) % MAX;
    }
    printf("\n");
}
int main()
{
    Queue q;
    Stack s;
    q.f = 0;
    q.r = 0;
    q.tag = 0;
    s.top = -1;
    for (int i = 0; i < MAX; i++)
        EnQueue(q, i);
    display(q);
    int x = 0;
    while (!(q.f == q.r && q.tag == 0))//不是队空
    {
        DeQueue(q, x);
        EnStack(s, x);
    }
    while (!(s.top == -1))//不是栈空
    {
        DeStack(s, x);
        EnQueue(q, x);
    }
    display(q);
    return 0;
}
