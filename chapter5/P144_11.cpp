//
// Created by 黎圣  on 2023/8/18.
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
void Release(tree &t)
{
    if (t != NULL)
    {
        Release(t->lchild);
        Release(t->rchild);
        free(t);
    }
}
void delete_x(tree &t, char x)
{
    if (t == NULL) return;
    if (t->data == x)
    {
        Release(t);
        t = NULL;
    }
    else
    {
        delete_x(t->lchild, x);
        delete_x(t->rchild, x);
    }
}
void display(tree t)
{
    if (t != NULL)
    {
        printf("%c ", t->data);
        display(t->lchild);
        display(t->rchild);
    }
}
int main()
{
    tree t;
    CreateTree(t);
    //ABD##E##CF##G##
    delete_x(t, 'C');
    display(t);
    return 0;
}
