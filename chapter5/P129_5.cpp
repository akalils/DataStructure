//
// Created by 黎圣  on 2023/8/8.
//
#include "iostream"
using namespace std;
struct Tree
{
    int data[12] = {-1,1,2,3,-1,4,-1,5,-1,-1,6,-1};
};
int Common(Tree t, int i ,int j)
{
    if (t.data[i] != -1 && t.data[j] != -1)
    {
        while (i != j)
        {
            if (i > j)
                i = i / 2;
            else if (i < j)
                j = j / 2;
        }
        return t.data[i];
    }
    else
        return -1;
}
int main()
{
    Tree t;
    int res = Common(t, 7, 10);
    printf("%d", res);

    return 0;
}
