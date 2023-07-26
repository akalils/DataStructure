////
//// Created by 黎圣  on 2023/7/21.
////
//#include "iostream"
//typedef struct node
//{
//    int data;
//    struct node *next;
//}*linklist;
//int a[5] = {2,1,3,7,5};
//int n = 5;
//void CreateList(linklist &L)
//{
//    L = (linklist)malloc(sizeof(struct node));
//    struct node *r = L;
//    struct node *s;
//    for (int i = 0; i < n; i++)
//    {
//        s = (struct node *)malloc(sizeof(struct node));
//        s->data = a[i];
//        r->next = s;
//        r = r->next;
//    }
//    r->next = NULL;
//}
//void DeleteMin(struct node *L)
//{
//    struct node *p;
//    struct node *q;
//    while (L->next != NULL)
//    {
//        struct node *r = L;
//        p = r->next;
//        while (p->next != NULL)
//        {
//            if (p->next->data < r->next->data)
//                r = p;
//            p = p->next;
//        }
//        printf("%d ", r->next->data);
//        q = r->next;
//        r->next = q->next;
//        free(q);
//    }
//    free(L);
//}
//int main()
//{
//    linklist L;
//    CreateList(L);
//    DeleteMin(L);
//    return 0;
//}