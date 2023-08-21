//
// Created by 黎圣  on 2023/8/21.
//
/*
 * 假设二叉树采用二叉链表存储结构，设计一个算法，求非空二叉树b的宽度
 * （即具有结点数最多的那一层的结点个数。）
 */
#include "iostream"
typedef struct TreeNode
{
    char data;
    struct TreeNode *lchild, *rchild;
}*tree;
struct Queue
{
    tree data[10];
    int f, r;
    int level[10];
};
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
int width(tree b)
{
    //辅助队列q
    Queue q;
    //指针p用来存放出队的元素
    struct TreeNode *p;
    //k用来记录出队结点的层次
    int k;
    //初始化队列
    q.r = q.f = -1;

    //入队根结点
    q.data[++q.r] = b;
    q.level[q.r] = 1;
    //层次遍历
    while (q.f < q.r)
    {
        //出队
        p = q.data[++q.f];
        k = q.level[q.f];

        if (p->lchild)
        {
            q.data[++q.r] = p->lchild;
            //进入队列的结点的层次为刚刚出队结点的层次+1
            q.level[q.r] = k + 1;
        }
        if (p->rchild)
        {
            q.data[++q.r] = p->rchild;
            q.level[q.r] = k + 1;
        }
    }
    //n用来记录每层的个数，max用来更新n的最大值，用i遍历队列
    int n, max = 0, i = 0;
    //此时元素已经全部入队了，k用来从第一层开始
    k = 1;
    while (i <= q.r)
    {
        //每层默认有0个结点
        n = 0;
        while (i <= q.r && q.level[i] == k)
        {
            //这一层的结点个数+1
            n++;
            i++;
        }
        //更新k的值让k去下一层
        k = q.level[i];
        if (n > max)
            max = n;
    }
    return max;
}
int main()
{
    tree t;
    CreateTree(t);
    //ABD##E##CF##G##
    printf("%d", width(t));
    return 0;
}
/*
             A
          B    C
        D  E  F  G
*/
