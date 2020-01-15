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
    ListNode* rotateRight(ListNode* head, int k) {
        if (!head || !head->next) return head;
        int n = 1;
        ListNode *p = head;
        while (p->next) {
            p = p->next;
            n ++;
        }
        p->next = head;
        int s = n - (k % n);
        p = head;
        while (--s > 0) p = p->next;
        head = p->next;
        p->next = NULL;
        return head;
    }
};
