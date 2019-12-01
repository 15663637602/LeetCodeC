//
// Created by hasee on 2019/12/1.
//

#include "mergeSort.h"

void msort(int *in, int tmp[], int start, int end) {
    if (start >= end)
        return;
    int mid = (end - start) / 2 + start;
    int start1 = start;
    int end1 = mid;
    int start2 = mid + 1;
    int end2 = end;
    msort(in, tmp, start1, end1);
    msort(in, tmp, start2, end2);
    int k = start;
    while (start1 <= end1 && start2 <= end2)
        tmp[k++] = in[start1] < in[start2] ? in[start1++] : in[start2++];
    while (start1 <= end1)
        tmp[k++] = in[start1++];
    while (start2 <= end2)
        tmp[k++] = in[start2++];
    for (int i = start; i <= end; ++i) {
        in[i] = tmp[i];
    }
}

void merge_sort(int* in, int len) {
    int tmp[len];
    msort(in, tmp, 0, len - 1);
}