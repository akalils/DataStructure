////
//// Created by 黎圣  on 2023/7/25.
////
//#include "iostream"
//typedef struct node
//{
//    int data;
//    struct node *next, *prior;
//}*linklist;
//int a[5] = {1,2,3,2,1};
//int n = 5;
//void CreateTowayList(linklist &L)
//{
//    L = (struct node*)malloc(sizeof(struct node));
//    struct node *s;
//    struct node *r = L;
//    L->prior = L;
//    L->next = L;
//    for (int i = 0; i < n; i++)
//    {
//        s = (struct node *)malloc(sizeof(struct node));
//        s->data = a[i];
//        s->next = r->next;
//        r->next->prior = s;
//        s->prior = r;
//        r->next = s;
//        r = s;
//        L->prior = s;
//    }
//}
//void display(linklist L)
//{
//    struct node *s = L->next;
//    while (s != L)
//    {
//        printf("%d ", s->data);
//        s = s->next;
//    }
//    printf("\n");
//}
//bool isOK(linklist L)
//{
//    struct node *p = L->next;
//    struct node *q = L->prior;
//    while (p != q && q->next != p)
//    {
//        if (p->data == q->data)
//        {
//            p = p->next;
//            q = q->prior;
//        }
//        else return false;
//    }
//    return true;
//}
//int main()
//{
//    linklist L;
//    CreateTowayList(L);
//    display(L);
//    if (isOK(L) == true) printf("true");
//    else printf("false");
//    return 0;
//}