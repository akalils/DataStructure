//
// Created by 黎圣  on 2023/8/2.
//
#include "iostream"
#define MAX 10
struct Queue
{
    int f, r, tag;
    int data[MAX];
};
//判断栈空
bool QueueEmpty(Queue q)
{
    if (q.f == q.r && q.tag == 0)
        return true;
    return false;
}
//判断栈满
bool QueueOverflow(Queue &q)
{
    if (q.f == q.r && q.tag == 1)
        return true;
    return false;
}
//入栈
bool EnQueue(Queue &q, int x)
{
    if (QueueOverflow(q) == true)
    {
        printf("队满，入队失败\n");
        return false;
    }
    q.data[q.r] = x;
    q.r = (q.r + 1) % MAX;
    q.tag = 1;
    return true;
}
//出栈
bool DeQueue(Queue &q, int &x)
{
    if (QueueEmpty(q) == true)
    {
        printf("队空，出队失败\n");
        return false;
    }
    x = q.data[q.f];
    q.f = (q.f + 1) % MAX;
    q.tag = 0;
    return true;
}
//这个可以不用写出来，我们为了方便看结果所以把队列中的元素打印出来
void display(Queue q)
{
    while (!QueueEmpty(q))
    {
        printf("%d ", q.data[q.f]);
        q.f = (q.f + 1) % MAX;
        q.tag = 0;
    }
    printf("\n");
}

//题目主代码
void car()
{
	//目标队列ans用来存放已经放在船上的车
	//队列h用来放货车
	//队列k用来放客车
    Queue ans, k, h;
    ans.f = 0, ans.r = 0, ans.tag = 0;
    k.f = 0, k.r = 0, k.tag = 0;
    h.f = 0, h.r = 0, h.tag = 0;
    //这个也不用写出来，也是为了方便看结果所以赋个值
    for (int i = 0; i < MAX; i++)
    {
        EnQueue(k, 1);
        EnQueue(h, 2);
    }
    //变量j来记录目标队列ans上已经放了几辆车
    //变量i来记录客车数
    //x存放出队元素
    int i = 0;
    int j = 0;
    int x = 0;
    while (j < 10)
    {
        if (!QueueEmpty(k) && i < 4)//我先入4个客车
        {
            DeQueue(k, x);
            EnQueue(ans, x);
            j++;
            i++;
        }
        else if (i == 4 && !QueueEmpty(h))//入一辆货车
        {
            DeQueue(h, x);
            EnQueue(ans, x);
            j++;
            i = 0;
        }
        else//
        {
        	//已经没有四辆客车了，并且还有剩余货车，并且现在目标队列里的车还不满10辆，用货车补
            while (i < 4 && !QueueEmpty(h) && j < 10)
            {
                DeQueue(h, x);
                EnQueue(ans, x);
                j++;
                i++;
            }
            //货车不够，让所有客车上船
            i = 0;//此时程序就会重新往上进入第一个if，也就是又开始入客车了
        }
        if (QueueEmpty(h) && QueueEmpty(k))
            break;
    }
    //这个也不用写出来
    printf("客车队列");
    display(k);
    printf("货车队列");
    display(h);
    printf("目标队列");
    display(ans);
}
int main()
{
    car();
    return 0;
}
