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
        ListNode head(0);
        ListNode *p1, *p2, *np = &head;
        for (p1 = l1,p2 = l2;
                p1 && p2 ;
                p1=p1->next, p2=p2->next, np=np->next) {
            int x = p1->val + p2->val + carry;
            np->next = new ListNode(x % 10);
            carry = x / 10;
        }
        while (p1) {
            int x = p1->val + carry;
            np->next = new ListNode(x % 10);
            carry = x / 10;
            np = np->next;
            p1 = p1->next;
        }
        while (p2) {
            int x = p2->val + carry;
            np->next = new ListNode(x % 10);
            carry = x / 10;
            np = np->next;
            p2 = p2->next;
        }
        if (carry) {
            np->next = new ListNode(carry);
        }
        return head.next;
    }
};
