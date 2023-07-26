//
// Created by 黎圣  on 2023/7/21.
//
#include "iostream"
struct Sqlist
{
    int data[50];
    int length;
};
bool del_min(struct Sqlist *sq, int *value)
{
    if (sq->length == 0)
    {
        printf("错误");
        return false;
    }
    int min_pos = 0;
    *value = sq->data[0];
    for (int i = 0; i < sq->length; i++)
    {
        if (*value > sq->data[i])
        {
            min_pos = i;
            *value = sq->data[i];
        }
    }
    sq->data[min_pos] = sq->data[sq->length - 1];
    sq->length--;
    return true;
}