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
    ListNode* reverseBetween(ListNode* head, int m, int n) {
        stack<ListNode*> stk;
        ListNode dumy(-1), *p1, *p2, *p;
        dumy.next = head;
        p1 = p2 = &dumy;
        while (--m > 0) p1=p1->next;
        while (n-- >= 0) p2=p2->next;
        p = p1->next;
        while (p != p2) {
            stk.push(p);
            p = p->next;
        }
        while (!stk.empty()) {
            p1->next = stk.top();
            p1 = p1->next;
            stk.pop();
        }
        p1->next = p2;
        return dumy.next;
    }
};
