//
// Created by hasee on 2019/11/21.
//

#include "uniquePaths.h"

int uniquePaths(int m, int n){
    int dp[m][n];

    for (int i = 1; i < m; ++i) {
        dp[i][0] = 1;
    }
    for (int j = 1; j < n; ++j) {
        dp[0][j] = 1;
    }

    for (int k = 1; k < m; ++k) {
        for (int i = 1; i < n; ++i) {
            dp[k][i] = dp[k][i - 1]+dp[k-1][i];
        }
    }

    return dp[m-1][n-1];

}