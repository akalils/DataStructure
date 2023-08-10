//
// Created by 黎圣  on 2023/8/10.
//
#include "iostream"
struct TreeNode
{
    char data;
    struct TreeNode *lchild, *rchild;
};
void CreateTree(struct TreeNode *&t)
{
    char ch = getchar();
    if (ch == '#')
        t = NULL;
    else
    {
        t = (struct TreeNode*)malloc(sizeof(struct TreeNode));
        t->lchild = NULL;
        t->rchild = NULL;
        t->data = ch;
        CreateTree(t->lchild);
        CreateTree(t->rchild);
    }
}
int depth(struct TreeNode *&t)
{
    if (t == NULL)
        return -1;
    struct TreeNode *q[10];
    int f = -1;
    int r = -1;
    int L = 0, depth = 0;
    struct TreeNode *p = t;
    q[++r] = p;//根结点入队
    while (f < r)
    {
        p = q[++f];
        if (p->lchild)
            q[++r] = p->lchild;
        if (p->rchild)
            q[++r] = p->rchild;
        if (L == f)
        {
            depth++;
            L = r;
        }
    }
    return depth;
}
int main()
{
    struct TreeNode *t;
    CreateTree(t);
    //ABD##E##CF###
    printf("%d ", depth(t));
    return 0;
}
