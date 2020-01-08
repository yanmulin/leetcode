/**
 * Definition for singly-linked list.
 * struct ListNode {
 *     int val;
 *     ListNode *next;
 *     ListNode(int x) : val(x), next(NULL) {}
 * };
 */

class Solution {
private:
    ListNode *constructListNodeByStack(stack<ListNode*> &stk, ListNode *first, ListNode *last) {
        assert(stk.size() > 0);
        ListNode *p = first;
        while (stk.size() > 0) {
            p->next = stk.top();
            stk.pop();
            p = p->next;
        }
        p->next = last;
        return p;
    }
public:
    ListNode* reverseKGroup(ListNode* head, int k) {
        if (!head || !head->next || k <= 1) return head;
        stack<ListNode*> stk;
        ListNode dumy(0), *p1 = &dumy, *p2 = head;
        dumy.next = head;
        do {
            int n;
            for (n=0;n<k&&p2;n++) {
                stk.push(p2);
                p2 = p2->next;
            }
            if (n == k) p1 = constructListNodeByStack(stk, p1, p2);
        } while (p2);
        return dumy.next;
    }
};
