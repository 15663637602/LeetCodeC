//
// Created by hasee on 2019/12/1.
//

#include <stdlib.h>
#include "sortList.h"

struct ListNode* merge(struct ListNode* l, struct ListNode* r)
{
    struct ListNode head;
    struct ListNode* p = &head;
    while(l && r)
    {
        if(l->val <= r->val) //collect left first when left and right are equal;
        {
            p->next = l;
            l = l->next;
        }
        else
        {
            p->next = r;
            r = r->next;
        }
        p = p->next;
    }
    p->next = (l == NULL ? r : l);
    return head.next; //return without the fake head;
}
struct ListNode* sortList(struct ListNode* head)
{
    if(head == NULL || head->next == NULL)
        return head;
    struct ListNode *s1 = head, *s2 = head->next;
    while(s2 && s2->next) //split the list into two halves;
    {
        s1 = s1->next;
        s2 = s2->next->next;
    }
    s2 = s1->next;
    s1->next = NULL;
    struct ListNode* a1 = sortList(head);
    struct ListNode* a2 = sortList(s2);
    return merge(a1, a2); //merge two parts by invoking recursive method;
}