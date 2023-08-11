//
// Created by 黎圣  on 2023/8/11.
//
#include "iostream"
struct TreeNode
{
    char data;
    struct TreeNode *lchild, *rchild;
};
int pos = 0;
struct TreeNode *build(char A[], char B[], int s, int e)
{
    if (s <= e)
    {
        struct TreeNode *root = (struct TreeNode*)malloc(sizeof(struct TreeNode));
        root->data = A[pos];
        int i = 0;
        for (i = s; i <= e; i++)
            if (B[i] == root->data)
                break;
        pos++;
        root->lchild = build(A, B, s, i - 1);
        root->rchild = build(A, B, i + 1, e);
        return root;
    }
    return NULL;
}
//后序遍历序列
void display(struct TreeNode *&t)
{
    if (t)
    {
        display(t->lchild);
        display(t->rchild);
        printf("%c ", t->data);
    }
}
int main()
{
    struct TreeNode *t;
    char A[] = {' ','A','B','D','E','C','F'};
    char B[] = {' ','D','B','E','A','F','C'};
    t = build(A, B, 1, 6);
    display(t);
    return 0;
}
