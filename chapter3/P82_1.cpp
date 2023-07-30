//
// Created by 黎圣  on 2023/7/30.
//
#include "iostream"
#define MAX 10
struct Queue
{
    int data[MAX];
    int f, r, tag;
};
int EnQueue(Queue &Q, int x)
{
    if (Q.f == Q.r && Q.tag == 1)
    {
        printf("队满，入队失败\n");
        return -1;
    }
    Q.data[Q.r] = x;
    printf("%d ", Q.data[Q.r]);
    Q.r = (Q.r + 1) % MAX;
    Q.tag = 1;
    return 1;
}
int DeQueue(Queue &Q, int x)
{
    if (Q.f == Q.r && Q.tag == 0)
    {
        printf("队空，出队失败\n");
        return -1;
    }
    x = Q.data[Q.f];
    Q.f = (Q.f + 1) % MAX;
    Q.tag = 0;
    return 1;
}
int main()
{
    Queue Q;
    Q.f = 0, Q.r = 0, Q.tag = 0;
    for (int i = 0; i < 10; i++)
        EnQueue(Q, i);
    printf("\n");
    EnQueue(Q, 0);
    for (int i = 0; i < 10; i++)
        DeQueue(Q, i);
    DeQueue(Q, 1);
    return 0;
}
