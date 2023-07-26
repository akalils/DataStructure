////
//// Created by 黎圣  on 2023/7/22.
////
//#include "iostream"
//struct node
//{
//    int data;
//    struct node *next;
//};
//int a[10] = {7,10,10,21,30,42,42,42,51,70};
//int n = 10;
//struct node *L;
//void CreateList(struct node *L)
//{
//    struct node *s;
//    struct node *r = L;
//    for (int i = 0; i < n; i++)
//    {
//        s = (struct node *)malloc(sizeof(struct node));
//        s->data = a[i];
//        r->next = s;
//        r = r->next;
//    }
//    s->next = NULL;
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
//void del_difference(struct node *L)
//{
//    if (L->next == NULL) return;
//    struct node *p = L;
//    struct node *q;
//    while (p->next != NULL)
//    {
//        q = p->next;
//        if (p->data == q->data)
//        {
//            p->next = q->next;
//            free(q);
//        }
//        else p = p->next;
//    }
//}
//int main()
//{
//    struct node *L;
//    CreateList(L);
//    display(L);
//    del_difference(L);
//    display(L);
//    return 0;
//}