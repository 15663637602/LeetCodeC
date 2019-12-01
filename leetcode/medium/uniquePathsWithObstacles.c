//
// Created by hasee on 2019/11/25.
//

#include <stdlib.h>
#include <string.h>
#include <stdio.h>
#include "uniquePathsWithObstacles.h"

int uniquePathsWithObstacles(int** obstacleGrid, int obstacleGridSize, int* obstacleGridColSize){
    if (obstacleGrid == NULL || obstacleGrid[0] == NULL || obstacleGrid[0][0] == 1) return 0;
    int r = obstacleGridSize;
    int c = *obstacleGridColSize;
    int dp[r][c];
    for (int i = 0; i < r; ++i) {
        for (int j = 0; j < c; ++j) {
            if (i == 0 && j == 0 && obstacleGrid[0][0] == 0) {
                dp[i][j] = 1;
                continue;
            }
            if (obstacleGrid[i][j] == 1) {
                dp[i][j] = 0;
                continue;
            }
            long count = 0;
            if (i > 0) {
                count += dp[i - 1][j];
            }
            if (j > 0) {
                count += dp[i][j - 1];
            }
            dp[i][j] = count;
        }
    }
    return dp[r - 1][c - 1];
}