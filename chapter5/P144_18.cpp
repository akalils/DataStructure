//
// Created by 黎圣  on 2023/8/29.
//
//在中序线索二叉树里查找指定结点在后序的前驱结点
#include "iostream"
using namespace std;
typedef struct TreeNode
{
    char data;
    struct TreeNode *lchild, *rchild;
    int ltag, rtag;
}*tree;
void CreateTree(tree &t)
{
    char ch = getchar();
    if (ch == '#')
        t = NULL;
    else
    {
        t = (struct TreeNode *)malloc(sizeof(struct TreeNode));
        t->data = ch;
        t->lchild = NULL;
        t->rchild = NULL;
        t->ltag = t->rtag = 0;
        CreateTree(t->lchild);
        CreateTree(t->rchild);
    }
}
struct TreeNode *pre;
void zx(tree &t)
{
    if (t)
    {
        zx(t->lchild);
        if (t->lchild == NULL)
        {
            t->ltag = 1;//无左孩子
            t->lchild = pre;
        }
        else
            t->ltag = 0;//有左孩子
        if (pre != NULL && pre->rchild == NULL)
        {
            pre->rtag = 1;
            pre->rchild = t;
        }
        pre = t;
        zx(t->rchild);
    }
}
tree Inpostpre(tree &t, struct TreeNode *p)
{
    struct TreeNode *q;//结果指针
    if (p->rtag == 0)//有右孩子就是右孩子
        q = p->rchild;
    else if (p->ltag == 0)//没有右孩子有左孩子就是左孩子
        q = p->lchild;
    else if (p->lchild == NULL)
        q = NULL;
    else
    {
        while (p->ltag == 1 && p->lchild != NULL)
            p = p->lchild;
        //若找到祖先结点 且有左孩子 结果就是左孩子
        if (p->ltag == 0)
            q = p->lchild;
        else
            q = NULL;
    }
    return q;
}
int main()
{
    tree t;
    CreateTree(t);
    //ABD##E##CF##G##
    zx(t);
    printf("%c ", Inpostpre(t, t->rchild)->data);
    return 0;
}
