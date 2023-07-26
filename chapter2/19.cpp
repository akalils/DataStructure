////
//// Created by 黎圣  on 2023/7/26.
////
//#include "iostream"
//typedef struct node
//{
//    int data;
//    struct node *next;
//}*linklist;
//int a[6] = {5,4,6,8,1,3};
//int n = 6;
//void CreateList(linklist &L)
//{
//    struct node *s;
//    struct node *r = L;
//    for (int i = 0; i < n; i++)
//    {
//        s = (linklist)malloc(sizeof(struct node));
//        s->data = a[i];
//        r->next = s;
//        r = r->next;
//    }
//    r->next = L;
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
//void delete_min(linklist &L)
//{
//    struct node *p, *r, *mp, *min;
//    while (L->next != L)
//    {
//        p = L->next, r = L, mp = r, min = p;
//        while (p != L)
//        {
//            if (min->data > p->data)
//            {
//                min = p;
//                mp = r;
//            }
//            else
//            {
//                r = p;
//                p = p->next;
//            }
//        }
//        printf("%d ", min->data);
//        mp->next = min->next;
//        free(min);
//    }
//    free(L);
//}
//int main()
//{
//    linklist L;
//    CreateList(L);
//    display(L);
//    delete_min(L);
//    return 0;
//}