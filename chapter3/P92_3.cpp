//
// Created by 黎圣  on 2023/8/2.
//
#include "iostream"
#define MAX 10
struct Stack
{
    int top;
    int n;
    double PnX;
}st[MAX];

//题目主代码
double ans(int n, double x)
{
    int top = -1;
    double fv1 = 1;
    double fv2 = 2 * x;
    //初始化左边部分
    for (int i = n; i >= 2; i--)
    {
        top++;
        st[top].n = i;
    }
    //初始化右边部分
    while (top >= 0)
    {
        st[top].PnX = 2 * x * fv2 - 2 * (st[top].n - 1) * fv1;
        fv1 = fv2;
        fv2 = st[top].PnX;
        top--;
    }
    if (n == 0) return fv1;
    else return fv2;
}
int main()
{
    double ans1 = ans(0, 1.9);
    printf("%lf", ans1);
    return 0;
}
