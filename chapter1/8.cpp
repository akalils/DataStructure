//
// Created by 黎圣  on 2023/7/20.
//
#include "iostream"
struct Sqlist
{
    int data[50];
    int length;
};
bool change_list(int A[], int m, int n)
{
    if(A == 0) return false;
    int *ans = (int*)malloc((m + n)*sizeof(int));
    for (int i = 0; i < m; i++)
        ans[i + n] = A[i];
    for (int i = 0; i < n; i++)
        ans[i] = A[i + m];
    for (int i = 0; i < m + n; i++)
        A[i] = ans[i];
    free(ans);
    return true;
}