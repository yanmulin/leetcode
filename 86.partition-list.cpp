/**
 * Definition for singly-linked list.
 * struct ListNode {
 *     int val;
 *     ListNode *next;
 *     ListNode(int x) : val(x), next(NULL) {}
 * };
 */
class Solution {
public:
    ListNode* partition(ListNode* head, int x) {
        if (!head) return head;
        ListNode dumy(-1), *p = &dumy, *pp;
        dumy.next = head;
        while (p->next && p->next->val < x)
            p = p->next;
        pp = p;
        while (p && p->next) {
            if (p->next->val < x) {
                ListNode *tmp = p->next;
                p->next = tmp->next;
                tmp->next = pp->next;
                pp->next = tmp;
                pp = pp->next;
            } else p = p->next;
        }
        return dumy.next;
    }
};
