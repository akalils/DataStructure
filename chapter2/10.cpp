////
//// Created by 黎圣  on 2023/7/22.
////
//#include "iostream"
//typedef struct node
//{
//    int data;
//    struct node *next;
//}*linklist;
//int a[6] = {1,2,3,4,5,6};
//linklist L2;
//void CreateList(linklist &L1)
//{
//    struct node *s;
//    struct node *r = L1;
//    L1->next = NULL;
//    for (int i = 0; i < 6; i++)
//    {
//        s = (struct node*)malloc(sizeof(struct node));
//        s->data = a[i];
//        r->next = s;
//        r = r->next;
//    }
//    s->next = NULL;
//}
//void display(linklist L1)
//{
//    struct node *p = L1->next;
//    while (p)
//    {
//        printf("%d ", p->data);
//        p = p->next;
//    }
//    printf("\n");
//}
//void CutList(struct node *L1)
//{
//    int i = 0;
//    L2 = (struct node *)malloc(sizeof(struct node));
//    L2->next = NULL;
//    struct node *p = L1->next;
//    struct node *r1 = L1;
//    struct node *r2 = L2;
//    L1->next = NULL;
//    while (p != NULL)
//    {
//        i++;
//        if (i % 2 == 0)//偶数
//        {
//            r2->next = p;
//            r2 = p;
//        }
//        else
//        {
//            r1->next = p;
//            r1 = p;
//        }
//        p = p->next;
//    }
//    r1->next = NULL;
//    r2->next = NULL;
//}
//int main()
//{
//    linklist L1;
//    CreateList(L1);
//    display(L1);
//    CutList(L1);
//    display(L1);
//    display(L2);
//    return 0;
//}