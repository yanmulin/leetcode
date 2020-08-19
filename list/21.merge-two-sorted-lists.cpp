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
    ListNode* mergeTwoLists(ListNode* l1, ListNode* l2) {
        ListNode dummy(0), *p = &dummy, *p1 = l1, *p2 = l2;
        while (p1 && p2) {
            if (p1->val > p2->val) swap(p1, p2);
            p->next = p1;
            p1 = p1->next;
            p = p->next;
        }
        if (p1) p->next = p1;
        if (p2) p->next = p2;
        return dummy.next;
    }
};
