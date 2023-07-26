////
//// Created by 黎圣  on 2023/7/20.
////
//#include <iostream>
//
//struct Sqlist
//{
//    int data[50];
//    int length;
//};
//
//int di12ti_1(int A[], int n)
//{
//    int *count = (int*) malloc(n*sizeof(int));
//    for (int i = 0; i < n; i++)
//        count[i] = 0;
//    for (int i = 0; i < n; i++)
//        count[A[i]] ++;
//    int ans = -1;
//    for (int i = 0; i < n; i++)
//    {
//        if (count[i] > n / 2)
//        {
//            ans = i;
//            break;
//        }
//    }
//    free(count);
//    return ans;
//}
//
//int di12ti_2(int A[], int n)
//{
//    int temp = A[0];
//    int count = 1;
//    for (int i = 0; i < n; i++)
//    {
//        if (temp = A[i])
//            count++;//好兄弟 不打了
//        else
//        {
//            if (count > 0)//看看我还有没有兄弟了
//                count--;//好兄弟死了
//            else
//            {
//                temp = A[i];//干就完了
//                count = 1;
//            }
//        }
//    }
//    //temp是幸存者
//    int cutcut = 0;
//    for (int i = 0; i < n; i++)
//    {
//        if (A[i] == temp)
//            cutcut++;
//    }
//    if (cutcut > n / 2)
//        return temp;
//    else
//        return -1;
//}