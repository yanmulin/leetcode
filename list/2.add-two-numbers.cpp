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
    ListNode* addTwoNumbers(ListNode* l1, ListNode* l2) {
        int carry = 0;
        ListNode dumy(0), *p = &dumy;
        ListNode *p1 = l1, *p2 = l2;
        while (p1 && p2) {
            int sum = p1->val + p2->val + carry;
            p->next = new ListNode(sum % 10);
            carry = sum / 10;
            p = p->next; p1 = p1->next; p2 = p2->next;
        }
        while (p1) {
            int sum = p1->val + carry;
            p->next = new ListNode(sum % 10);
            carry = sum / 10;
            p = p->next; p1 = p1->next; 
        }
        while (p2) {
            int sum = p2->val + carry;
            p->next = new ListNode(sum % 10);
            carry = sum / 10;
            p = p->next; p2 = p2->next; 
        }
        if (carry > 0) p->next = new ListNode(carry);
        return dumy.next;
    }
};
