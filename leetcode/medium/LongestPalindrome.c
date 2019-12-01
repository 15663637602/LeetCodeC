//
// Created by hasee on 2019/10/24.
//

#include <stdlib.h>
#include <string.h>
#include <stdbool.h>
#include "LongestPalindrome.h"

int expandMirror(char* src, int left, int right, int max) {
    int L = left;
    int R = right;
    while (L >= 0 && R< max && src[L] == src[R]) {
        L--, R++;
    }
    return R - L - 1;
}

char * longestPalindrome(char * s){
    if (s == NULL || strlen(s) < 2)
        return s;
    int src_len = (int) strlen(s);
    char *res = (char *)malloc((size_t) src_len);
    int start = 0, end = 0;
    for (int i = 0; i < src_len; ++i) {
        int lenSingleMiddle = expandMirror(s, i, i, src_len);
        int lenDoubleMiddle = expandMirror(s, i, i+1, src_len);
        int res_len = lenSingleMiddle > lenDoubleMiddle ? lenSingleMiddle : lenDoubleMiddle;
        if (res_len > end - start) {
            start = i - (res_len - 1) / 2;
            end = i + res_len / 2;
        }
    }
    strncpy(res, s+start, (size_t) (end - start + 1));
    res[end - start + 1] = '\0';
    return res;
}

char * longestPalindrome2(char * s){
    if (s == NULL || strlen(s) < 2)
        return s;
    int src_len = (int) strlen(s);
    bool** isPal = (bool **)malloc(sizeof(bool *) * src_len);
    for (int i = 0; i < src_len; ++i) {
        isPal[i] = (bool *)malloc(sizeof(bool) * src_len);
        for (int j = 0; j < src_len; ++j) {
            isPal[i][j] = false;
        }
        isPal[i][i] = true;
    }

    int max = 0;
    int start = 0;

    for (int l = 1; l < src_len; ++l) {
        for (int i = 0; i < l; ++i) {
            isPal[i][l] = (s[i] == s[l] && ((l - i == 1) || isPal[i+1][l-1]));
            if (isPal[i][l]) {
                if (max < l - i + 1) {
                    start = i;
                    max = l - i + 1;
                }
            }
        }
    }

    for (int k = 0; k < src_len; ++k) {
        free(isPal[k]);
    }
    free(isPal);

    char *res = (char *)malloc(max);
    strncpy(res, s+start, max);
    res[max] = '\0';
//    strncpy_s(res, max, s+start, max);
    return res;
}

