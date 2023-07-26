////
//// Created by 黎圣  on 2023/7/25.
////
//#include "iostream"
//typedef struct node
//{
//    int data;
//    struct node *next;
//}*linklist;
//int a[3] = {1,2,3};
//int b[3] = {4,5,6,};
//int n = 3;
//int m = 3;
//void CreateList1(linklist &h1)
//{
//    h1 = (linklist)malloc(sizeof(struct node));
//    struct node *s;
//    struct node *r = h1;
//    for (int i = 0; i < n; i++)
//    {
//        s = (linklist)malloc(sizeof(struct node));
//        s->data = a[i];
//        r->next = s;
//        r = r->next;
//    }
//    r->next = h1;
//}
//void CreateList2(linklist &h2)
//{
//    h2 = (linklist)malloc(sizeof(struct node));
//    struct node *s;
//    struct node *r = h2;
//    for (int i = 0; i < m; i++)
//    {
//        s = (linklist)malloc(sizeof(struct node));
//        s->data = b[i];
//        r->next = s;
//        r = r->next;
//    }
//    s->next = h2;
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
//void add(linklist &h1, linklist &h2)
//{
//    struct node *p1 = h1->next;
//    struct node *p2 = h2->next;
//    while (p1->next != h1)
//        p1 = p1->next;
//    while (p2->next != h2)
//        p2 = p2->next;
//    p1->next = h2->next;
//    p2->next = h1;
//}
//int main()
//{
//    linklist h1, h2;
//    CreateList1(h1);
//    CreateList2(h2);
//    display(h1);
//    display(h2);
//    add(h1, h2);
//    display(h1);
//    return 0;
//}