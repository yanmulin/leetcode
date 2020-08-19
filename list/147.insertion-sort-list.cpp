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
    ListNode* insertionSortList(ListNode* head) {
        if (!head) return head;
        ListNode dummy(0), *p = head;
        dummy.next = head;
        while (p && p->next) {
            ListNode *node = p->next, *q = &dummy;
            int val = node->val;
            p->next = p->next->next; // delete node
            while (q != p && val > q->next->val)
                q = q->next;
            node->next = q->next; // insert node
            q->next = node;
            if (q == p) p = p->next;
        }
        return dummy.next;
    }
};
