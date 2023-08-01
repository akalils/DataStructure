//
// Created by 黎圣  on 2023/8/1.
//
#include "iostream"
#define MAX 10
struct Stack
{
    char data[MAX];
    int top;
};
bool StackEmpty(Stack s)
{
    if (s.top == -1)
        return true;
    return false;
}
bool StackOverflow(Stack s)
{
    if (s.top == MAX - 1)
        return true;
    return false;
}
bool EnStack(Stack &s, char x)
{
    if (StackOverflow(s) == true)
    {
        printf("栈满，入栈失败\n");
        return false;
    }
    s.data[++s.top] = x;
    return true;
}
int DeStack(Stack &s, char &x)
{
    if (StackEmpty(s) == true)
    {
        printf("栈空，出栈失败\n");
        return false;
    }
    x = s.data[s.top--];
    return 1;
}
bool Sort(char str[])
{
    Stack s;
    s.top = -1;
    char ans[MAX + 1];
    int j = 0;
    for (int i = 0; i < MAX; i++)
    {
        if (str[i] == 'H')
            EnStack(s, str[i]);
        else if (str[i] == 'S')
        {
            ans[j] = str[i];
            j++;
        }
    }
    char c;
    while (!StackEmpty(s))
    {
        DeStack(s, c);
        ans[j] = c;
        j++;
    }
    for (int i = 0; i < MAX; i++)
        printf("%c", ans[i]);
    printf("\n");
}
bool Sort_lisheng(char str[])
{
    Stack s;
    s.top = -1;
    char ans[MAX];
    int j = 0;
    for (int i = 0; i < MAX; i++)
    {
        EnStack(s, str[i]);
        if (str[i] == 'S')
            DeStack(s, ans[j++]);
    }
    while (!StackEmpty(s))
    {
        DeStack(s, ans[j]);
        j++;
    }
    for (int i = 0; i < MAX; i++)
    {
        printf("%c", ans[i]);
    }
    printf("\n");
}
int main()
{
    char str[MAX] = "HSSHHHS";
    printf("%s\n", str);
    Sort(str);
    return 0;
}
