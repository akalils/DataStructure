//
// Created by 黎圣  on 2023/8/19.
//
#include "iostream"
#define MAX 15
typedef struct TreeNode
{
    char data;
    struct TreeNode *lchild, *rchild;
}*tree;
struct Stack
{
    struct TreeNode *t;
    int tag;//tag=0左孩子已将访问过，tag=1表示右孩子已经访问过
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
void print_parent(tree t, char x)
{
    Stack s[10];
    int top = 0;
    while (t != NULL || top > 0)
    {
        //从根结点开始向左延伸压入栈中 井且 结点的值不为x
        while (t != NULL && t->data != x)
        {
            s[++top].t = t;
            s[top].tag = 0;
            t = t->lchild;
        }
        //如果找到了值为x的结点 将栈中的结点值输出
        if (t != NULL && t->data == x)
        {
            for (int i = 1; i <= top; i++)
                printf("%c", s[i].t->data);
            break;
        }
        //判断当前栈顶的结点的tag值为1的活 依次退桟
        while (top != 0 && s[top].tag == 1)
        {
            top--;
        }
        //当前栈顶不为0 将栈顶的taq值赋值为1 结点指向该结点的右孩子
        if (top != 0)
        {
            s[top].tag = 1;
            t = s[top].t->rchild;
        }
    }
}
int main()
{
    tree t;
    CreateTree(t);
    //ABD##E##CF##G##
    print_x(t, 'G');
    return 0;
}
