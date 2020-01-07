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
    ListNode* removeNthFromEnd(ListNode* head, int n) {
        if (!head || n <= 0) return head;
        ListNode dumy(0), *pm, *pn;
        dumy.next = head;
        pm = pn = &dumy;
        while (pm->next && n-- > 0) pm = pm->next;
        if (!pm->next && n > 0) return head;
        while (pm->next) {
            pm = pm->next;
            pn = pn->next;
        }
        pn->next = pn->next->next;
        return dumy.next;
    }
};
