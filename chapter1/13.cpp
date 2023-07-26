////
//// Created by 黎圣  on 2023/7/20.
////
//struct Sqlist
//{
//    int data[50];
//    int length;
//};
//
//int di13ti(int A[], int n)
//{
//    int *flag = (int *) malloc((n + 1) * sizeof(int));
//    for (int i = 0; i < n; i++)
//    {
//        if (A[i] >= 0 && A[i] <= n)
//            flag[A[i]] = 1;//打标记，证明这个数字有了
//    }
//    int i = 0;
//    for (i = 1; i < n; i++)
//    {
//        if (A[i] = 0)//数组里没有这个数字
//            break;
//    }
//    free(flag);
//    return i;
//}