////
//// Created by 黎圣  on 2023/7/21.
////
//
//#include "iostream"
//typedef struct node
//{
//    int data;
//    struct node *next;
//}*linklist;
//int a[4] = {1,2,3,4};
//int n = 4;
//void Create_list(linklist &L)
//{
//    L = (linklist)malloc(sizeof(struct node));
//    struct node *s;
//    struct node *r = L;
//    L->next = NULL;
//    for (int i = 0; i < n; i++)
//    {
//        s = (struct node*)malloc(sizeof(struct node));
//        s->data = a[i];
//        r->next = s;
//        r = r->next;
//    }
//    r->next = NULL;
//}
//void display(struct node *L)
//{
//    struct node *s = L->next;
//    while (s != NULL)
//    {
//        printf("%d ", s->data);
//        s = s->next;
//    }
//    printf("\n");
//}
//void reverse(struct node *L)
//{
//    struct node *p,*r;
//    p = L->next;
//    L->next = NULL;
//    while (p != NULL)
//    {
//        r = p->next;
//        p->next = L->next;
//        L->next = p;
//        p = r;
//    }
//}
//int main()
//{
//    linklist L;
//    Create_list(L);
//    display(L);
//    reverse(L);
//    display(L);
//    return 0;
//}