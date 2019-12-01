//
// Created by hasee on 2019/10/30.
//

#include <stdlib.h>
#include <string.h>
#include "bitmap.h"

char* init_bm(int size) {
    char *res = (char *)malloc((size_t) (size / BITSPERWORD));
    memset(res, 0, (size_t) (size / BITSPERWORD));
    return res;
}

void free_bm(char* bm) {
    free(bm);
    bm = NULL;
}

void setTrue_bm(char* bm, int index) {
    bm[index >> SHIFT] |= (1 << (index & MASK));
}

void setFalse_bm(char* bm, int index) {
    bm[index >> SHIFT] &= ~(1 << (index & MASK));
}

int get_bm(char* bm, int index) {
    return (bm[index >> SHIFT] & (1 << (index & MASK))) > 0 ? 1 : 0;
}