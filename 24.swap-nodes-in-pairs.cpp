/**
 * Definition for singly-linked list.
 * struct ListNode {
 *     int val;
 *     ListNode *next;
 *     ListNode(int x) : val(x), next(NULL) {}
 * };
 */
#include <assert.h>
class Solution {
private:
    void swapFollowingTwo(ListNode *p) {
        assert(p && p->next && p->next->next);
        ListNode *tmp = p->next;
        p->next = tmp->next;
        tmp->next = p->next->next;
        p->next->next = tmp;
    }
public:
    ListNode* swapPairs(ListNode* head) {
        if (!head || !head->next) return head;
        ListNode dumy(0), *p1 = &dumy;
        dumy.next = head;
        ListNode *p2 = head, *tmp;
        int i;
        while (p2) {
            for (i=0,tmp=p2;i<2&&tmp;i++) tmp=tmp->next;
            if (i < 2) return dumy.next;
            swapFollowingTwo(p1);
            p1 = p2;
            p2 = p2->next;
        }
        return dumy.next;
    }
};
