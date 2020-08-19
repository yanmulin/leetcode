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
    bool hasCycle(ListNode *head) {
        unordered_set<ListNode*> seen;
        ListNode *p = head;
        while (p) {
            if (seen.count(p)) return true;
            seen.insert(p);
            p = p->next;
        }
        return false;
    }
};
