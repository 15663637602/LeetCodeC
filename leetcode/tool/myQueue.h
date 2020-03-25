//
// Created by hasee on 2019/12/4.
//

#ifndef INC_1_MYQUEUE_H
#define INC_1_MYQUEUE_H

#include <stdlib.h>
#include <stdbool.h>

#define SIZE 1000
typedef struct {
    int size;
    int arr[SIZE];
    int front;
    int rear;
} MyQueue;

MyQueue* myQueueCreate();

void myQueuePush(MyQueue* obj, int x);

int myQueuePop(MyQueue* obj);

int myQueuePeek(MyQueue* obj);

bool myQueueEmpty(MyQueue* obj);

void myQueueFree(MyQueue* obj);

#endif //INC_1_MYQUEUE_H
