//
// Created by 黎圣  on 2023/8/22.
//
/*
 * 设有一棵满二叉树(所有结点值均不同)，已知其先序序列为pre，设计一个算法求其后序序列post.
 */
#include "iostream"
using namespace std;
void PreToPost(char pre[], int l1, int h1, char post[], int l2, int h2)
{
    int half;
    if (l1 <= h1)
    {
        post[h2] = pre[l1];
        half = (h1 - l1) / 2;
        PreToPost(pre, l1 + 1, l1 + half, post, l2, l2 + half - 1);
        PreToPost(pre, l1 + half + 1, h1, post,l2 + half, h2 - 1);
    }
}
int main()
{
    char pre[8] = "ABDECFG";
    char post[8];
    PreToPost(pre, 0, 6, post, 0, 6);
    for (int i = 0; i < 7; i++)
        printf("%c ", post[i]);
    return 0;
}
