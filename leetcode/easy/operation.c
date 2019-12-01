//
// Created by hasee on 2019/10/30.
//

#include "operation.h"

int plus(int a, int b) {
    int res = a ^ b;
    int carry = (a & b) << 1;
    int sum = res;
    while (carry != 0) {
        sum = res ^ carry;
        carry = (res & carry) << 1;
        res = sum;
    }
    return sum;
}

int subtraction(int a, int b) {
    return plus(a, opposite(b));
}

int multiply(int a, int b) {
    int multiplend = a > 0 ? a : opposite(a);
    int multiplier = b > 0 ? b : opposite(b);
    int res = 0;
    while (multiplier > 0) {
        if ((multiplier & 0x1) > 0) {
            res = plus(res, multiplend);
        }
        multiplend <<= 1;
        multiplier >>= 1;
    }
    if ((a ^ b) < 0)
        res = opposite(res);
    return res;
}

int divide(int a, int b) {
    int divided = a > 0 ? a : opposite(a);
    int divisor = b > 0 ? b : opposite(b);
    int res = 0;
    for (int i = 31; i >= 0; i = subtraction(i, 1)) {
        if ((divided >> i) >= divisor) {
            res = plus(res, (1 << i));
            divided = subtraction(divided, (divisor << i));
        }
    }
    if ((a ^ b) < 0)
        res = opposite(res);
    return res;
}

int opposite(int a) {
    return plus(~a, 1);
}