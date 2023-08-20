//
// Created by 黎圣  on 2023/8/20.
//
/*
 * 13. 设一棵二叉树的结点结构为 (IIINK,INFO, RLINK)，ROOT 为指向该二叉树根结点的指针，
 * p和g分别为指向该二叉树中任意两个结点的指针，试编写算法ANCESTOR (ROOT，p，q，r)，找到
 * p和q的最近公共祖先结点r。
 */
#include "iostream"
using namespace std;
typedef struct TreeNode
{
    char data;
    struct TreeNode *lchild, *rchild;
}*tree, treenode;
struct Stack
{
    struct TreeNode *t;
    int tag;
};
void CreateTree(tree &t)
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
struct TreeNode *Ancestor(tree t,struct TreeNode *p, struct TreeNode *q)
{
    //两个辅助栈
    Stack s1[10], s2[10];
    //栈顶指针初始化
    int top1 = 0, top2;
    //遍历二叉树的指针
    struct TreeNode *l = t;
    while (l != NULL || top1 > 0)
    {
        //像左延伸入栈
        while (l != NULL)
        {
            s1[++top1].t = l;
            s1[top1].tag = 0;
            l = l->lchild;
        }
        //判断是否结点是否为p
        //栈1不为空切栈顶元素tag值为1
        while (top1 != 0 && s1[top1].tag == 1)
        {
            //如果栈顶元素就是p我们就把栈1中的元素复制到栈2中
            if (s1[top1].t == p)
            {
                for (int i = 1; i <= top1; i++)
                {
                    s2[i] = s1[i];
                }
                top2 = top1;
            }
            //如果栈顶元素就是q，我们就开始和栈2中的元素开始匹配
            if (s1[top1].t == q)
            {
                for (int i = top1; i > 0; i--)
                    for (int j = top2; j > 0; j--)
                        if (s2[j].t == s1[i].t)
                            return s1[i].t;
            }
            //两个情况都不满足的同时tag=1就出栈
            top1--;
        }
        //右子树入栈
        if (top1 != 0)
        {
            s1[top1].tag = 1;
            l = s1[top1].t->rchild;
        }
    }
    return NULL;
}
int main()
{
    tree t;
    CreateTree(t);
    struct TreeNode *p = t->lchild->rchild;
    struct TreeNode *q = t->rchild->lchild;

    //ABD##E##CF##G##
    printf("%c", Ancestor(t, p, q)->data);
    return 0;
}
