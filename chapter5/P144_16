//
// Created by 黎圣  on 2023/8/25.
//
#include "iostream"
typedef struct TreeNode
{
    char data;
    struct TreeNode *lchild, *rchild;
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
        CreateTree(t->lchild);
        CreateTree(t->rchild);
    }
}
struct TreeNode *pre = NULL, *head = (struct TreeNode*)malloc(sizeof(struct TreeNode));
tree Inorder(tree &t)
{
    if (t)
    {
        Inorder(t->lchild);
        if (t->lchild == NULL && t->rchild == NULL)
        {
            //是否是第一个
            //是
            if (pre == NULL)
            {
                head = t;
                pre = t;
            }
            //不是第一个
            else
            {
                pre->rchild = t;
                pre = t;
            }
        }
        Inorder(t->rchild);
    }
    return head;
}
int main()
{
    tree t;
    CreateTree(t);
    //ABD##E##CF##G##
    Inorder(t);
    while (head)
    {
        printf("%c ", head->data);
        head = head->rchild;
    }
    return 0;
}
