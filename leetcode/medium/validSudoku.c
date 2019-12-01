//
// Created by hasee on 2019/11/18.
//

#include "validSudoku.h"


bool isValidSudoku(char** board, int boardSize, int* boardColSize){
    bool map[9] = {false};
    for (int i = 0; i < 9; ++i) {
        for (int j = 0; j < 9; ++j) {
            if (board[i][j] == '.') {
                continue;
            } else if (map[board[i][j] - 49] == true) {
                return false;
            } else {
                map[board[i][j] - 49] = true;
            }
        }
        for (int k = 0; k < 9; ++k) {
            map[k] = false;
        }
    }

    for (int i = 0; i < 9; ++i) {
        for (int j = 0; j < 9; ++j) {
            if (board[j][i] == '.') {
                continue;
            } else if (map[board[j][i] - 49] == true) {
                return false;
            } else {
                map[board[j][i] - 49] = true;
            }
        }
        for (int k = 0; k < 9; ++k) {
            map[k] = false;
        }
    }

    for (int m = 0; m < 9; m+=3) {
        for (int l = 0; l < 9; l+=3) {
            for (int i = m; i < m + 3; ++i) {
                for (int j = l; j < l + 3; ++j) {
                    if (board[i][j] == '.') {
                        continue;
                    } else if (map[board[i][j] - 49] == true) {
                        return false;
                    } else {
                        map[board[i][j] - 49] = true;
                    }
                }
            }
            for (int k = 0; k < 9; ++k) {
                map[k] = false;
            }
        }
    }
    return true;
}