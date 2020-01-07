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
        ListNode *p1 = l1, *p2 = l2;
        ListNode dumy(0), *p = &dumy;
        p->next = NULL;
        while (p1 && p2) {
            if (p1->val > p2->val) {
                p->next = new ListNode(p2->val);
                p2 = p2->next;
            } else {
                p->next = new ListNode(p1->val);
                p1 = p1->next;
            }
            p = p->next;
        }
        while (p1) {
            p->next = new ListNode(p1->val);
            p = p->next;
            p1 = p1->next;
        }
        while (p2) {
            p->next = new ListNode(p2->val);
            p = p->next;
            p2 = p2->next;
        }
        return dumy.next;
    }
};
