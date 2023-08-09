//
// Created by 黎圣  on 2023/8/9.
//
#include "iostream"
#define MAX 10
struct TreeNode
{
    char data;
    struct TreeNode *lchild, *rchild;
};
struct Stack
{
    struct TreeNode *data[MAX];
    int top;
};
struct Queue
{
    struct TreeNode *data[MAX];
    int f, r ,tag;
};
bool StackEmpty(Stack &s)
{
    if (s.top == -1)
        return true;
    return false;
}
bool StackOverflow(Stack &s)
{
    if (s.top == MAX - 1)
        return true;
    return false;
}
bool EnStack(Stack &s, struct TreeNode *&p)
{
    if (StackOverflow(s))
    {
        printf("栈满，入栈失败\n");
        return false;
    }
    else
    {
        s.data[++s.top] = p;
        return true;
    }
}
int DeStack(Stack &s, struct TreeNode *&p)
{
    if (StackEmpty(s))
    {
        printf("栈空，出栈失败\n");
        return false;
    }
    else
        p = s.data[s.top--];
}
bool QueueEmtpy(Queue &q)
{
    if (q.f == q.r && q.tag == 0)
        return true;
    return false;
}
bool QueueOverflow(Queue &q)
{
    if (q.f == q.r && q.tag == 1)
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
    if (QueueEmtpy(q))
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
void ergodic(struct TreeNode *&t)
{
    Stack s;
    Queue q;
    struct TreeNode *p = t;
    if (t != NULL)
    {
        s.top = -1;
        q.f = 0, q.r = 0, q.tag = 0;
        EnQueue(q, p);
        while (!QueueEmtpy(q))
        {
            DeQueue(q, p);
            EnStack(s, p);
            if (p->lchild != NULL)
                EnQueue(q, p->lchild);
            if (p->rchild != NULL)
                EnQueue(q, p->rchild);
        }
        while (!StackEmpty(s))
        {
            DeStack(s, p);
            printf("%c ", p->data);
        }
    }
}
int main()
{
    //ABD##E##CF##G##
    struct TreeNode *t;
    CreateTree(t);
    ergodic(t);
    return 0;
}
