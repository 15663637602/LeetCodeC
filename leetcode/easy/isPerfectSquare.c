//
// Created by hasee on 2019/12/1.
//

#include "isPerfectSquare.h"
#include <math.h>

bool isPerfectSquare(int num){
    double res = sqrt(num);
    if ((res - (int)res) == 0)
        return 1;
    else
        return 0;
}