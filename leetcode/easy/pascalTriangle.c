//
// Created by hasee on 2019/12/2.
//

#include <stdlib.h>
#include "pascalTriangle.h"

int** generate(int numRows, int* returnSize, int** returnColumnSizes)
{
    *returnSize = numRows;
    int n = numRows;
    int **res = (int**)malloc(sizeof(int*) * n);
    *returnColumnSizes = (int*)malloc(sizeof(int) * n);
    for (int i = 0; i < n; ++i) {
        res[i] = (int*)malloc(sizeof(int) * (i + 1));
        (*returnColumnSizes)[i] = i + 1;
        res[i][0] = 1;
        res[i][i] = 1;
    }
    n = 2;
    while (n < numRows) {
        for (int i = 1; i < n; ++i) {
            res[n][i] = res[n - 1][i - 1] + res[n - 1][i];
        }
        n++;
    }
    return res;
}