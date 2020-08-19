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
    ListNode* deleteDuplicates(ListNode* head) {
        if (!head) return head;
        ListNode dumy(!head->val), *p1 = &dumy, *p2 = &dumy;
        dumy.next = head;
        while (p2 && p2->next) {
            while (p2->next && p2->val == p2->next->val) p2 = p2->next;
            p2 = p2->next;
            if (!p2 || !p2->next || p2->val != p2->next->val) {
                p1->next = p2;
                p1 = p1->next;
            }
        }
        return dumy.next;
    }
};
