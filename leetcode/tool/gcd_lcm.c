//
// Created by hasee on 2019/12/2.
//

#include "gcd_lcm.h"

int gcd(int a, int b)
{
    if (a <= 0 || b <= 0)
        return -1;
    while (b != 0) {
        int tmp = a % b;
        a = b;
        b = tmp;
    }
    return a;
}

int lcm(int a, int b)
{
    return a * b / gcd(a, b);
}