////
//// Created by 黎圣  on 2023/7/20.
////
//struct Sqlist
//{
//    int data[50];
//    int length;
//};
//
//bool merge_list(struct Sqlist *sq1, struct Sqlist *sq2, struct Sqlist *returnsq)
//{
//    if (sq1->length == 0 || sq2->length == 0) return false;
//    int i, j, n;
//    while (i < sq1->length && j < sq2->length)
//    {
//        if (sq1->data[i] < sq2->data[j])
//        {
//            returnsq->data[n] = sq1->data[i];
//            i++;
//            n++;
//        }
//        else if (sq1->data[i] >= sq2->data[j])
//        {
//            returnsq->data[n] = sq2->data[j];
//            j++;
//            n++;
//        }
//    }
//    while (i < sq1->length)
//    {
//        returnsq->data[n] = sq1->data[i];
//        i++;
//        n++;
//    }
//    while (j < sq2->length)
//    {
//        returnsq->data[n] = sq2->data[j];
//        j++;
//        n++;
//    }
//    returnsq->length = n;
//    return true;
//}
