//
// Created by 黎圣  on 2023/7/29.
//
#include "iostream"
bool isOK(char a[], int n)
{
    int i = 0;
    int o = 0;
    for (int j = 0; j < n; j++)
    {
        if (a[j] == 'I') i++;
        else o++;
        if (o > i) return false;
    }
    if (o == i) return true;
    return false;
}
int main()
{
    char a[8] = {'I','I','I','O','O','I','O','O'};
    int n = 8;
    if (isOK(a, n) == true) printf("true");
    else
        printf("false");
    return 0;
}