////
//// Created by 黎圣  on 2023/7/24.
////
//#include "iostream"
//struct node
//{
//    int data;
//    struct node *next;
//};
//int a[6] = {1,3,4,5,10,11};
//int n = 6;
//int b[5] = {3,5,7,9,10};
//int m = 5;
//void CreateA(struct node *L)
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
//    r->next = NULL;
//}
//void CreateB(struct node *L)
//{
//    struct node *s;
//    struct node *r = L;
//    for (int i = 0; i < m; i++)
//    {
//        s = (struct node *)malloc(sizeof(struct node));
//        s->data = b[i];
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
//void merge_list(struct node *A, struct node *B)
//{
//    struct node *r, *q;
//    r = A;
//    struct node *p1 = A->next;
//    struct node *p2 = B->next;
//    while (p1 && p2)
//    {
//        if (p1->data < p2->data)
//        {
//            q = p1;
//            p1 = p1->next;
//            free(q);
//        }
//        else if (p1->data == p2->data)
//        {
//            r->next = p1;
//            r = p1;
//            p1 = p1->next;
//            q = p2;
//            p2 = p2->next;
//            free(q);
//        }
//        else
//        {
//            q = p2;
//            p2 = p2->next;
//            free(q);
//        }
//    }
//    while (p1)
//    {
//        q = p1;
//        p1 = p1->next;
//        free(q);
//    }
//    while (p2)
//    {
//        q = p2;
//        p2 = p2->next;
//        free(q);
//    }
//    r->next = NULL;
//}
//int main()
//{
//    struct node *A;
//    struct node *B;
//    CreateA(A);
//    CreateB(B);
//    display(A);
//    display(B);
//    merge_list(A, B);
//    display(A);
//    return 0;
//}