//
// Created by hasee on 2019/10/21.
//

#include <limits.h>
#include "reverseInt.h"

int reverse(int i) {
    int num = 0;
    long long sum = 0;
    do {
        num = i % 10;
        i = i / 10;
        sum = sum * 10 + num;
    } while (i != 0);

    return (int) ((sum < INT_MIN || sum > INT_MAX) ? 0 : sum);
}