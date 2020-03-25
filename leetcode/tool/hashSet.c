//
// Created by hasee on 2019/12/4.
//

#include <stdbool.h>
#include <stdlib.h>
#include <mem.h>
#include "hashSet.h"

#define BUCKET 1000

typedef struct {
    int **values;
} MyHashSet;

MyHashSet *myHashSetCreate() {
    MyHashSet *hs = (MyHashSet *) malloc(sizeof(MyHashSet));
    hs->values = (int **) malloc(BUCKET * sizeof(int *));

    for (ssize_t i = 0; i < BUCKET; ++i)
        hs->values[i] = (int *) malloc(BUCKET * sizeof(int));

    return hs;
}

void myHashSetAdd(MyHashSet *hs, int key) {
    hs->values[key / 1000][key % 1000] = key;
}

void myHashSetRemove(MyHashSet *hs, int key) {
    hs->values[key / 1000][key % 1000] = -1;
}

bool myHashSetContains(MyHashSet *hs, int key) {
    return hs->values[key / 1000][key % 1000] == key;
}

void myHashSetFree(MyHashSet *hs) {
    for (ssize_t i = 0; i < BUCKET; ++i)
        free(hs->values[i]);

    free(hs->values);
}