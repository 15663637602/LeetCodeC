#include <stdio.h>
#include <stdlib.h>
#include "lib/uthash.h"
#include "leetcode/medium/linkedList/sortList.h"
#include "leetcode/tool/mergeSort.h"

struct number_hash {
    int value;
    int index;
    UT_hash_handle hh;
};

void destroy_table(struct number_hash** table) {
    struct number_hash* curr;
    struct number_hash* tmp;

    HASH_ITER(hh, *table, curr, tmp) {
        HASH_DEL(*table, curr);
        free(curr);
    }
}

int* twoSum2(int* nums, int numsSize, int target) {
    struct number_hash* table = NULL;
    struct number_hash* element;
    int* ret = (int*) malloc(2 * sizeof(int));
    int remaining;
    for (int i = 0; i < numsSize; ++i) {
        remaining = target - nums[i];

        // Find if there has already been an element such that the sum is target
        HASH_FIND_INT(table, &remaining, element);
        if (element) {
            ret[0] = element->index;
            ret[1] = i;
            break;
        }

        // Add the new number to the hash table if it doesn't exist already
        HASH_FIND_INT(table, &nums[i], element);
        if (!element) {
            element = (struct number_hash *) malloc(sizeof(*element));
            element->value = nums[i];
            element->index = i;

            HASH_ADD_INT(table, value, element);
        }
    }

    destroy_table(&table);

    return ret;
}

int* twoSum(int* nums, int numsSize, int target, int* returnSize){
    *returnSize = 2;
    int tmp[200000];
    long int temp;
    for (int i = 0; i < 20000; ++i) {
        tmp[i] = -1;
    }
    for (int j = 0; j < numsSize; ++j) {
        temp = target - nums[j] + 10000;
        if (tmp[temp] != -1) {
            int *res = (int *)malloc(sizeof(int)*2);
            res[0] = tmp[temp];
            res[1] = j;
            return res;
        }
        if (tmp[nums[j] + 10000] == -1) {
            tmp[nums[j] + 10000] = j;
        }
    }
    return NULL;
}



int myAtoi(char * str) {
    int flag = 1;
    long res = 0;
    if (str == NULL)
        return 0;
    while (*str == ' ' || *str == '\t')
        str++;
    if (*str == '-'){
        flag = -1;
        str++;
    } else if (*str == '+') {
        flag = 1;
        str++;
    } else if (*str < '0' || *str > '9') {
        return 0;
    }
    while (*str >= '0' && *str <= '9') {
        if (res > INT_MAX / 10 || (res == INT_MAX / 10 && *str - 48 > 7)) {
            return flag > 0 ? INT_MAX : INT_MIN;
        }
        res = res * 10 + *str - 48;
        str++;
    }
    return flag < 0 ? -res : res;
}



int main() {

//    struct ListNode l5 = {0, NULL}, *pl5 = &l5;
    struct ListNode l4 = {3, NULL}, *pl4 = &l4;
    struct ListNode l3 = {1, pl4}, *pl3 = &l3;
    struct ListNode l2 = {2, pl3}, *pl2 = &l2;
    struct ListNode l1 = {4, pl2}, *pl1 = &l1;

    struct ListNode* p = sortList(pl1);
    while (p != NULL) {
        int t = p->val;
        printf("%d -> ", t);
        p = p->next;
    }

    return 0;
}