//
// Created by 黎圣  on 2023/8/26.
//
/*
 * 试设计判断两颗二叉树是否相似的算法。所谓二叉树T1和T2相似，指的是
 * T1和T2都是空的二叉树
 * 或都只有一个根结点
 * 或T1的左子树和T2的左子树是相似的，且T1的右子树和T2的右子树是相似的。
 */
#include "iostream"
using namespace std;
typedef struct TreeNode
{
    char data;
    struct TreeNode *lchild, *rchild;
}*tree;
void CreateTree(tree &t)
{
    char ch;
    cin >> ch;
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
//递归比较左右子树 空+空 = 1 空+非空 = 0
int similar(tree T1, tree T2)
{
    int left, right;
    if (T1 == NULL && T2 == NULL)
        return 1;
    else if (T1 == NULL || T2 == NULL)
        return 0;
    else
    {
        left = similar(T1->lchild, T2->lchild);
        right = similar(T1->lchild, T2->rchild);
        return (left && right);
    }
}
int main()
{
    tree t1, t2;
    CreateTree(t1);
    CreateTree(t2);
    printf("%d", similar(t1, t2));
    return 0;
}
