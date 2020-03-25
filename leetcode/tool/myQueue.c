//
// Created by hasee on 2019/12/4.
//

#include "myQueue.h"

MyQueue* myQueueCreate()
{
    MyQueue* q = (MyQueue*)malloc(sizeof(MyQueue));
    q->size = 0;
    q->front = 0;
    q->rear = 0;
    return q;
}

void myQueuePush(MyQueue* obj, int x)
{
    obj->size++;
    obj->arr[obj->rear] = x;
    obj->rear = (obj->rear + 1) % SIZE;
}

int myQueuePop(MyQueue* obj)
{
    int n = obj->arr[obj->front];
    obj->front = (obj->front + 1) % SIZE;
    obj->size--;
    return n;
}

int myQueuePeek(MyQueue* obj)
{
    return obj->arr[obj->front];
}

bool myQueueEmpty(MyQueue* obj)
{
    return obj->size == 0;
}

void myQueueFree(MyQueue* obj)
{
    free(obj);
}