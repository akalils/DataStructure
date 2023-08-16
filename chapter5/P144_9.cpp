//
// Created by 黎圣  on 2023/8/16.
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
bool QueueEmpty(Queue q)
{
    if (q.r == q.f && q.tag == 0)
        return true;
    return false;
}
bool QueueOverflow(Queue q)
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
        printf("队空，入队失败\n");
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
void display(struct TreeNode *t)
{
    if (t)
    {
        printf("%c ", t->data);
        display(t->lchild);
        display(t->rchild);
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
void reverse1(struct TreeNode *&t)
{
    Queue q;
    q.r = q.f = q.tag = 0;
    struct TreeNode *p = t;
    EnQueue(q, p);
    printf("%c ",p->data);
    while (!QueueEmpty(q))
    {
        DeQueue(q, p);
        if (p->rchild)
        {
            EnQueue(q, p->rchild);
            if (p->lchild)
                EnQueue(q, p->lchild);
        }
        else
        {
            if (p->lchild)
                EnQueue(q, p->lchild);
        }
    }
}
void reverse2(struct TreeNode *&t)
{
    struct TreeNode *p;
    if (t)
    {
        reverse2(t->lchild);
        reverse2(t->rchild);
        p = t->lchild;
        t->lchild = t->rchild;
        t->rchild = p;
    }
}
int main()
{
    struct TreeNode *t;
    CreateTree(t);
    //ABD##E##CF##G##
    display(t);
    printf("\n");
    printf("方法二交换后：");
    reverse2(t);
    display(t);
    return 0;
}
