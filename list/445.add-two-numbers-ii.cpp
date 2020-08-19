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
        stack<int> stk1, stk2;
        ListNode *p1 = l1, *p2 = l2;
        while (p1) {
            stk1.push(p1->val);
            p1 = p1->next;
        }
        while (p2) {
            stk2.push(p2->val);
            p2 = p2->next;
        }
        int sum = 0;
        ListNode dumy(0), *p;
        while (!stk1.empty() && !stk2.empty()) {
            sum += stk1.top() + stk2.top();
            p = new ListNode(sum % 10);
            p->next = dumy.next;
            dumy.next = p;
            stk1.pop(); stk2.pop();
            sum /= 10;
        }
        while (!stk1.empty()) {
            sum += stk1.top();
            p = new ListNode(sum % 10);
            p->next = dumy.next;
            dumy.next = p;
            stk1.pop();
            sum /= 10;
        }
        while (!stk2.empty()) {
            sum += stk2.top();
            p = new ListNode(sum % 10);
            p->next = dumy.next;
            dumy.next = p;
            stk2.pop();
            sum /= 10;
        }
        if (sum > 0) {
            p = new ListNode(sum % 10);
            p->next = dumy.next;
            dumy.next = p;
        }
        return dumy.next;
    }
};
