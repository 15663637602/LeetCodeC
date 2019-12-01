//
// Created by hasee on 2019/10/15.
//
#include "sorts.h"

void bubbleSort(int *arr, int n) {
    for (int i = 0; i < n; ++i) {
        for (int j = 0; j < n - i - 1; ++j) {
            if (arr[j] > arr[j + 1]) {
                int temp = arr[j];
                arr[j] = arr[j + 1];
                arr[j + 1] = temp;
            }
        }
    }
}

void quickSorts(int *arr, int left, int right) {
    int l = left;
    int r = right;
    int pivot = arr[left];
    while (l < r) {
        while (l < r && pivot < arr[r])
            r--;
        if (l < r) {
            arr[l] = arr[r];
            l++;
        }
        while (l < r && arr[l] < pivot)
            l++;
        if (l < r) {
            arr[r] = arr[l];
            r--;
        }
    }
    arr[l] = pivot; //l = r at this point
    if (left < l)
        quickSorts(arr, left, l - 1);
    if (r < right)
        quickSorts(arr, l + 1, right);
}

void quickSort(int *arr, int n) {
    quickSorts(arr, 0, n - 1);
}