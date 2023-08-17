//
// Created by 黎圣  on 2023/8/17.
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
        t = (struct TreeNode*)malloc(sizeof(struct TreeNode));
        t->data = ch;
        t->lchild = NULL;
        t->rchild = NULL;
        CreateTree(t->lchild);
        CreateTree(t->rchild);
    }
}
int i = 1;
char ch;
char PreNode(tree &t, int k)
{
    if (t == NULL)
        return '#';
    if (i == k)
        return t->data;
    else
        i++;
    ch = PreNode(t->lchild, k);
    if (ch != '#')
        return ch;
    ch = PreNode(t->rchild, k);
    return ch;
}
int main()
{
    tree t;
    CreateTree(t);
    //ABD##E##CF##G##
    printf("%c", PreNode(t, 4));
    return 0;
}
