//
// Created by hasee on 2019/12/2.
//

#include "uglyNumI.h"


bool isUgly(int num)
{
    if (num < 1)
        return 0;
    for (int i = 2; i < 6; ++i) {
        if (i == 4)
            continue;
        while ((num % i) == 0) {
            num /= i;
        }
    }
    return num == 1;
}
