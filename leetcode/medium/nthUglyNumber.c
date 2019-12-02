//
// Created by hasee on 2019/12/1.
//

#include <stdio.h>
#include "nthUglyNumber.h"

int nthUglyNumber(int n, int a, int b, int c){
    long aIndex = 1l;
    long bIndex = 1l;
    long cIndex = 1l;
    long aValue = a;
    long bValue = b;
    long cValue = c;
    long res = a;

    while (n > 0) {
        aValue = a * aIndex;
        bValue = b * bIndex;
        cValue = c * cIndex;
        if (aValue < bValue && aValue < cValue) {
            res = aValue;
            aIndex++;
            n--;
        } else if (bValue < aValue && bValue < cValue) {
            res = bValue;
            bIndex++;
            n--;
        } else if (cValue < bValue && cValue < aValue) {
            res = cValue;
            cIndex++;
            n--;
        } else {
            if (aValue == bValue) {
                a < b ? aIndex++ : bIndex++;
            } else if (aValue == cValue) {
                a < c ? aIndex++ : cIndex++;
            } else if (cValue == bValue) {
                b < c ? bIndex++ : cIndex++;
            }
        }
    }
    return res;
}