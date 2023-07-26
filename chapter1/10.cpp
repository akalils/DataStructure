////
//// Created by 黎圣  on 2023/7/20.
////
//#include "iostream"
//struct Sqlist
//{
//    int data[50];
//    int length;
//};
//
//bool change(int R[], int p, int n)
//{
//    if (R == 0) return false;
//    int* ans = (int*)malloc((p + n)*sizeof(int));
//    for (int i = 0; i < p; i++)
//        ans[i + n] = R[i];
//    for (int i = 0; i < n; i++)
//        ans[i] = R[i + p];
//    for (int i = 0; i < p + n; i++)
//        R[i] = ans[i];
//    free(ans);
//    return true;
//}