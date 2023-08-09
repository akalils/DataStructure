//
// Created by 黎圣  on 2023/8/8.
//
//非递归实现后序遍历二叉树

#include "iostream"
using namespace std;
struct TreeNode
{
    char data;
    struct TreeNode* lchild, *rchild;
    int tag;
};
void CreateTree(struct TreeNode* &t)
{
    char ch;
    ch = getchar();
    if (ch == '#')
        t = NULL;
    else
    {
        t = (struct TreeNode*)malloc(sizeof(struct TreeNode));
        t->lchild = NULL;
        t->rchild = NULL;
        t->tag = 0;
        t->data = ch;
        CreateTree(t->lchild);
        CreateTree(t->rchild);
    }
}
void back(struct TreeNode* t)
{
    struct TreeNode *stack[100];
    int top = -1;
    struct TreeNode *p = t;
    while (p || top != -1)//p存在或者栈不为空，只要满足一个条件都能访问二叉树
    {
        if (p != NULL)
        {
            top++;
            stack[top] = p;//入栈
            p = p->lchild;//指针p移向左孩子
        }
        else
        {
            p = stack[top];//指针p指向栈顶
            if (p->rchild != NULL && p->rchild->tag == 0)
                p = p->rchild;//移向右子树
            else
            {
                p = stack[top];
                top--;
                printf("%c ", p->data);
                p->tag = 1;//改变标志域，证明该结点已经访问过
                p = NULL;//置空
            }
        }
    }
}
int main()
{
    struct TreeNode *t;
    CreateTree(t);
    back(t);
    //ABD##E##C##
    return 0;
}
