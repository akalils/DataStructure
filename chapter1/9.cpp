////
//// Created by 黎圣  on 2023/7/20.
////
//
//struct Sqlist
//{
//    int data[50];
//    int length;
//};
//
//bool search_x(struct Sqlist *sq, int x)
//{
//    if (sq->length == 0) return false;
//    int left = 0;
//    int right = sq->length - 1;
//    int mid = 0;
//    while (left <= right)
//    {
//        mid = (left + right) / 2;
//        if (sq->data[mid] == x) break;
//        if (sq->data[mid] < x)
//            left = mid + 1;
//        else
//            right = mid - 1;
//    }
//    if (sq->data[mid] == x && sq->data[mid] != sq->length)
//    {
//        int temp = sq->data[mid];
//        sq->data[mid] = sq->data[mid + 1];
//        sq->data[mid + 1] = temp;
//    }
//    if (sq->data[mid] != x)
//    {
//        int i = 0;
//        for (i = sq->length - 1; i > right; i--)
//            sq->data[i + 1] = sq->data[i];
//        sq->data[i + 1] = x;
//    }
//    return true;
//}
