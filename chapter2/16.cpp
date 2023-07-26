////
//// Created by 黎圣  on 2023/7/24.
////
//#include "iostream"
//struct node
//{
//    int data;
//    struct node *next;
//};
//int a[10] = {1,2,3,4,5,6,3,4,5,7};
//int n = 10;
//int b[4] = {3,4,5,7};
//int m = 4;
//void CreateA(struct node *A)
//{
//    struct node *s;
//    struct node *r = A;
//    for (int i = 0; i < n; i++)
//    {
//        s = (struct node *)malloc(sizeof(struct node));
//        s->data = a[i];
//        r->next = s;
//        r = r->next;
//    }
//    s->next = NULL;
//}
//void CreateB(struct node *B)
//{
//    struct node *s;
//    struct node *r = B;
//    for (int i = 0; i < m; i++)
//    {
//        s = (struct node *)malloc(sizeof(struct node));
//        s->data = b[i];
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
//bool isok(struct node *A, struct node *B)
//{
//    struct node *p1 = A->next;
//    struct node *p2 = B->next;
//    struct node *r = A->next;
//    while (p1 && p2)
//    {
//        if (p1->data != p2->data)
//        {
//            r = r->next;
//            p1 = r;
//            p2 = B->next;
//        }
//        else
//        {
//            p1 = p1->next;
//            p2 = p2->next;
//        }
//    }
//    if (p2 == NULL)
//    {
//        printf("TRUE");
//        return true;
//    }
//    else
//    {
//        printf("FALSE");
//        return false;
//    }
//}
//int main()
//{
//    struct node *A, *B;
//    CreateA(A);
//    CreateB(B);
//    display(A);
//    display(B);
//    isok(A, B);
//    return 0;
//}
