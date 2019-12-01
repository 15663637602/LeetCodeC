//
// Created by hasee on 2019/11/28.
//

#include <stdlib.h>
#include "removeNthFromEnd.h"
#include "stdio.h"
struct ListNode* removeNthFromEnd(struct ListNode* head, int n) {
    int sum = 1;
    struct ListNode* pivot = head;
    while (pivot->next != NULL) {
        sum++;
        pivot = pivot->next;
    }
    if (sum == 1) {
        return NULL;
    }
    if (n == sum) {
        struct ListNode* res = head->next;
        free(head);
        return res;
    }
    int index = sum - n;
    pivot = head;
    for (int i = 0; i < index - 1; ++i) {
        pivot = pivot->next;
    }
    struct ListNode *del = pivot->next;
    pivot->next = pivot->next->next;
    free(del);
    return head;
}