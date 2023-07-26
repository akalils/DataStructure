////
//// Created by 黎圣  on 2023/7/23.
////
//#include "iostream"
//struct node
//{
//    int data;
//    struct node *next;
//}*linklist;
//int a1[3] = {1,2,7};
//int a2[2] = {5,6};
//int n = 3;
//int m = 2;
//void CreateList1(struct node *L1)
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
//        s = (struct node *)malloc(sizeof(struct node));
//        s->data = a2[i];
//        r->next = s;
//        r = r->next;
//    }
//    s->next = NULL;
//}
//void display(struct node *L1, struct node *L2)
//{
//    struct node *s = L1->next;
//    struct node *r = L2->next;
//    while (s)
//    {
//        printf("%d ", s->data);
//        s = s->next;
//    }
//    printf("\n");
//    while (r)
//    {
//        printf("%d ", r->data);
//        r = r->next;
//    }
//    printf("\n");
//}
//void hebing(struct node *L1, struct node *L2)
//{
//    struct node *p1 = L1->next;
//    struct node *p2 = L2->next;
//    struct node *r;
//    L1->next = NULL;
//    while (p1 && p2)
//    {
//        if (p1->data <= p2->data)
//        {
//            r = p1->next;
//            p1->next = L1->next;
//            L1->next = p1;
//            p1 = r;
//        }
//        else
//        {
//            r = p2->next;
//            p2->next = L1->next;
//            L1->next = p2;
//            p2 = r;
//        }
//    }
//    if (p1 != NULL) p2 = p1;
//    while (p2)
//    {
//        r = p2->next;
//        p2->next = L1->next;
//        L1->next = p2;
//        p2 = r;
//    }
//    free(p2);
//}
//int main()
//{
//    struct node *L1, *L2;
//    CreateList1(L1);
//    CreateList2(L2);
//    display(L1, L2);
//    hebing(L1, L2);
//    display(L1, L2);
//    return 0;
//}