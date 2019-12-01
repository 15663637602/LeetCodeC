//
// Created by hasee on 2019/11/27.
//

#include "ZigZag.h"
#include <string.h>
#include <stdlib.h>

char * convert(char * s, int numRows){
    int len = strlen(s);

    if(len<=numRows || numRows<=1){
        return s;
    }

    char **a = malloc(numRows * sizeof(char*));
    for (int j = 0; j < numRows; ++j) {
        a[j] = malloc(sizeof(char)*(len+1));
        memset(a[j], 0, len+1);
    }
    int index = 0;
    int flag = 0;
    while (*s != '\0') {
        if (index == numRows - 1 || index == 0) flag = 1 - flag;
        char tmp[2] = {0};
        tmp[0] = *s;
        strcat(a[index], tmp);
        if (flag){
            index++;
        } else {
            index--;
        }
        s++;
    }
    char *res = malloc(sizeof(char)*(len + 1));
    memset(res, 0, len + 1);
    for (int i = 0; i < numRows; ++i) {
        strcat(res, a[i]);
    }
    for (int k = 0; k < numRows; ++k) {
        free(a[k]);
    }
    free(a);
    return res;
}


char* convert2(char* s, int numRows) {
    int len=strlen(s);
    if(len<=numRows || numRows==1){
        return s;
    }
    int step = 2*numRows-2;
    int i=0,j=0,myStep=0,it=0;
    char *ns=(char*)malloc(sizeof(char)*(len+1));
    for(i=0;i<len+1;i++){
        ns[i]=0;
    }
    for(i=0;i<numRows;i++){
        j=i;
        myStep=step-2*i;
        while(j<len){
            ns[it++]=s[j];
            if(!(i==0|| i==numRows-1)){
                if(j+myStep<len){
                    ns[it++]=s[j+myStep];
                }
            }
            j+=step;
        }
    }
    return ns;
}