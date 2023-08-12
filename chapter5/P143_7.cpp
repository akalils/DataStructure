//
// Created by 黎圣  on 2023/8/12.
//
#include "iostream"
#define MAX 15
struct TreeNode
{
    char data;
    struct TreeNode *lcihld, *rchild;
};
struct Queue
{
    struct TreeNode *data[MAX];
    int r, f, tag;
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
        t->lcihld = NULL;
        t->rchild = NULL;
        CreateTree(t->lcihld);
        CreateTree(t->rchild);
    }
}
bool isOK(struct TreeNode *&t)
{
    Queue q;
    q.f = 0, q.r = 0, q.tag = 0;
    bool ans = true;
    bool flag = true;
    struct TreeNode *p = t;
    if (t == NULL)
        ans = true;
    if (t->lcihld != NULL && t->rchild != NULL)
        ans = true;
    EnQueue(q, p);
    while (!QueueEmpty(q))
    {
        DeQueue(q, p);

        //有左孩子
        if (p->lcihld != NULL)
        {
            if (flag == true)//之前都不缺孩子
            {
                EnQueue(q, p->lcihld);
                if (p->rchild != NULL)
                    EnQueue(q, p->rchild);
                else//没有右孩子
                    flag = false;
            }
            else if (flag == false)//之前就缺孩子
                ans = false;
        }

        //无左孩子
        else if (t->lcihld == NULL)
        {
            flag = false;
            if (p->rchild)//没有左孩子但是有右孩子，不符合完全二叉树
                ans = false;
        }
    }
    if (ans == true)
        return true;
    else
        return false;
}
int main()
{
    struct TreeNode *t;
    //ABD##E##CF##G## 是完全二叉树
    //ABD###CE##F## 不是
    CreateTree(t);
    if(isOK(t) == true)
        printf("是完全二叉树\n");
    else
        printf("不是完全二叉树\n");
    return 0;
}
