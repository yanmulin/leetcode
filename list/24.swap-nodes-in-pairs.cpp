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
    ListNode* swapPairs(ListNode* head) {
        ListNode dumy(0), *p1, *p2;
        if (!head) return head;
        dumy.next = head; p1 = &dumy; p2 = head;
        while (p2 && p2->next) {
            p1->next = p2->next;
            p2->next = p1->next->next;
            p1->next->next = p2;
            p1 = p2;
            p2 = p2->next;
        }
        return dumy.next;
    }
};
