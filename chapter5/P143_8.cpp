//
// Created by 黎圣  on 2023/8/13.
//
#include "iostream"
#define MAX 15
struct TreeNode
{
    char data;
    struct TreeNode *lchild, *rchild;
};
struct Queue
{
    struct TreeNode *data[MAX];
    int f, r, tag;
};
bool QueueEmpty(Queue &q)
{
    if (q.r == q.f && q.tag == 0)
        return true;
    return false;
}
bool QueueOverflow(Queue &q)
{
    if (q.r == q.f && q.tag == 1)
        return true;
    return false;
}
bool EnQueue(Queue &q, struct TreeNode *&p)
{
    if (QueueOverflow(q))
    {
        printf("队满，入队失败\n");
        return false;
    }
    else
    {
        q.data[q.r] = p;
        q.r = (q.r + 1) % MAX;
        q.tag = 1;
        return true;
    }
}
bool DeQueue(Queue &q, struct TreeNode *&p)
{
    if (QueueEmpty(q))
    {
        printf("队空，出队失败\n");
        return false;
    }
    else
    {
        p = q.data[q.f];
        q.f = (q.f + 1) % MAX;
        q.tag = 0;
        return true;
    }
}
void CreateTree(struct TreeNode *&t)
{
    char ch = getchar();
    if (ch == '#')
        t = NULL;
    else
    {
        t = (struct TreeNode*)malloc(sizeof(struct TreeNode));
        t->data = ch;
        t->lchild = NULL;
        t->rchild = NULL;
        CreateTree(t->lchild);
        CreateTree(t->rchild);
    }
}
int num(struct TreeNode *t)
{
    Queue q;
    q.r = q.f = q.tag = 0;
    struct TreeNode *p = t;
    EnQueue(q, p);
    int num = 0;
    while (!QueueEmpty(q))
    {
        DeQueue(q, p);
        if (p->lchild)
        {
            EnQueue(q, p->lchild);
            if (p->rchild)
            {
                EnQueue(q, p->rchild);
                num++;
            }
        }
        else
        {
            if (p->rchild)
                EnQueue(q, p->rchild);
        }
    }
    return num;
}
void display(struct TreeNode *t)
{
    if (t)
    {
        printf("%c ", t->data);
        display(t->lchild);
        display(t->rchild);
    }
}
int main()
{
    struct TreeNode *t;
    CreateTree(t);
    //ABD###CE##F## 2
    //ABD##E##CF##G## 3
    display(t);
    printf("\n%d", num(t));
    return 0;
}
