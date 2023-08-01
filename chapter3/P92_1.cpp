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
    if (s.top == -1) return true;
    return false;
}
bool StackOverflow(Stack s)
{
    if (s.top == MAX - 1) return true;
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
bool isRight(char *str)
{
    Stack s;
    s.top = -1;
    int i = 0;
    char ans;
    while (str[i] != '\0')
    {
        if (str[i] == '(' || str[i] == '[' || str[i] == '{')
            EnStack(s, str[i]);
        else if (str[i] == ')')
        {
            DeStack(s, ans);
            if (ans != '(') return false;
        }
        else if (str[i] == ']')
        {
            DeStack(s, ans);
            if (ans != '[') return false;
        }
        else if (str[i] == '}')
        {
            DeStack(s, ans);
            if (ans != '{') return false;
        }
        i++;
    }
    if (StackEmpty(s) == true) return true;
    else return false;
}
int main()
{
    char *str = (char*)"(){}[]";
    printf("%s\n", str);
    if (isRight(str) == true)
        printf("匹配");
    else
        printf("不匹配");
    return 0;
}
