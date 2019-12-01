//
// Created by hasee on 2019/10/30.
//

#ifndef INC_1_BITMAP_H
#define INC_1_BITMAP_H
#define BITSPERWORD 8
#define SHIFT 3
#define MASK 0x7
char* init_bm(int size);
void free_bm(char* bm);
void setTrue_bm(char* bm, int index);
void setFalse_bm(char* bm, int index);
int get_bm(char* bm, int index);
#endif //INC_1_BITMAP_H
