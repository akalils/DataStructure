////
//// Created by 黎圣  on 2023/7/23.
////
//#include "iostream"
//struct node
//{
//    int data;
//    struct node *next;
//};
//int a1[4] = {1,2,3,4};
//int a2[5] = {1,4,5,7,9};
//int n = 4;
//int m = 5;
//void CreateList(struct node *L1)
//{
//    struct node *s;
//    struct node *r = L1;
//    for (int i = 0; i < n; i++)
//    {
//        s = (struct node *)malloc(sizeof(struct node));
//        s->data = a1[i];
//        r->next = s;
//        r = r->next;
//    }
//    s->next = NULL;
//}
//void CreateList2(struct node *L2)
//{
//    struct node *s;
//    struct node *r = L2;
//    for (int i = 0; i < m; i++)
//    {
//        s = (struct node *)malloc (sizeof(struct node));
//        s->data = a2[i];
//        r->next = s;
//        r = r->next;
//    }
//    r->next = NULL;
//}
//void display(struct node *L)
//{
//    struct node *s = L->next;
//    while (s)
//    {
//        printf("%d ", s->data);
//        s = s->next;
//    }
//    printf("\n");
//}
//struct node *L3;
//void merge(struct node *L1, struct node *L2)
//{
//    struct node *p1 = L1->next;
//    struct node *p2 = L2->next;
//    L3 = (struct node*)malloc(sizeof(struct node));
//    struct node *r = L3;
//    struct node *s;
//    while (p1 && p2)
//    {
//        if (p1->data < p2->data) p1 = p1->next;
//        else if (p1->data > p2->data) p2 = p2->next;
//        else
//        {
//            s = (struct node *)malloc(sizeof(struct node));
//            s->data = p1->data;
//            r->next = s;
//            r = s;
//            p1 = p1->next;
//            p2 = p2->next;
//        }
//    }
//    r->next = NULL;
//}
//int main()
//{
//    struct node *L, *L2;
//    CreateList(L);
//    CreateList2(L2);
//    display(L);
//    display(L2);
//    merge(L, L2);
//    display(L3);
//    return 0;
//}