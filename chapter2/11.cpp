////
//// Created by 黎圣  on 2023/7/22.
////
//#include "iostream"
//struct node
//{
//    int data;
//    struct node *next;
//}*linklist;
//int a[10] = {1,2,3,4,5,6,7,8,9,10};
//int n = 10;
//struct node *L2;
//void CreateList(struct node *L1)
//{
//    struct node *s;
//    struct node *r = L1;
//    for (int i = 0; i < n; i++)
//    {
//        s = (struct node*)malloc(sizeof(struct node));
//        s->data = a[i];
//        r->next = s;
//        r = r->next;
//    }
//    s->next = NULL;
//}
//void display(struct node *L1)
//{
//    struct node *s = L1->next;
//    while (s)
//    {
//        printf("%d ", s->data);
//        s = s->next;
//    }
//    printf("\n");
//}
//void CutList(struct node *L1)
//{
//    L2 = (struct node *)malloc(sizeof(struct node));
//    struct node *r = L1;
//    struct node *p = L1->next;
//    struct node *q;
//    L2->next = NULL;
//    while (p)
//    {
//        r->next = p;
//        r = p;
//        p = p->next;
//        if(p != NULL) q = p->next;
//        p->next = L2->next;
//        L2->next = p;
//        p = q;
//    }
//    r->next = NULL;
//}
//int main()
//{
//    struct node *L1;
//    CreateList(L1);
//    display(L1);
//    CutList(L1);
//    display(L1);
//    display(L2);
//    return 0;
//}