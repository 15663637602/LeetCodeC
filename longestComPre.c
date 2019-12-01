//
// Created by hasee on 2019/11/14.
//

#include <stdlib.h>
#include <string.h>
#include "longestComPre.h"

char * longestCommonPrefix(char ** strs, int strsSize){
    if(strsSize<1)
        return "";

    int len = strlen(strs[0]) + 1;

    char *res = (char *)malloc(len);
    memset(res, 0, len);

    int index = 0;
    int flag = 1;

    for (index; (index < len) && flag; index++){
        char *tmp = strs[0];
        for (int i = 1; i < strsSize; ++i) {
            if (index >= strlen(strs[i]) || (tmp[index] != strs[i][index])) {
                flag = 0;
                break;
            }
        }
    }
    strncpy(res, strs[0], index - 1);
    return res;
}