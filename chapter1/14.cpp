////
//// Created by 黎圣  on 2023/7/20.
////
//struct Sqlist
//{
//    int data[50];
//    int length;
//};
//
//int abs(int x)
//{
//    if (x >= 0)
//        return x;
//    else
//        return -x;
//}
//int di14ti(struct Sqlist *A, struct Sqlist *B, struct Sqlist *C)
//{
//    int temp = 0;
//    int ans = abs(A->data[0] - B->data[0]) + abs(B->data[0] - C->data[0]) + abs(C->data[0] - A->data[0]);
//    for (int i = 0; i < A->length; i++)
//        for (int j = 0; j < B->length; j++)
//            for (int k = 0; k < C->length; k++)
//            {
//                temp = abs(A->data[i] - B->data[j]) + abs(B->data[j] - C->data[k]) + abs(C->data[k] - A->data[i]);
//                if (temp < ans)
//                    ans = temp;
//            }
//    return ans;
//}