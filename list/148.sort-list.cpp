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
    pair<ListNode*, ListNode*> mergeTwoList(ListNode* l1, ListNode* l2) {
        ListNode dummy(0), *tail = &dummy;
        while (l1 && l2) {
            if (l1->val > l2->val) swap(l1, l2);
            tail = tail->next = l1;
            l1 = l1->next;
        }
        tail->next = l1 ? l1 : l2;
        while (tail->next) tail = tail->next;
        return {dummy.next, tail};
    }
    ListNode* split(ListNode* head, int n) {
        while (--n && head) head = head->next;
        ListNode *rest = head ? head->next : NULL;
        if (head) head->next = NULL;
        return rest;
    }
public:
    ListNode* sortList(ListNode* head) {
        int len = 0;
        ListNode dummy(0), *tail, *cur, *l, *r;
        cur = &dummy;
        dummy.next = head;
        while ((cur=cur->next) != NULL) len ++;
        for (int n=1;n<len;n<<=1) {
            cur = dummy.next;
            tail = &dummy;
            while (cur) {
                l = cur;
                r = split(l, n);
                cur = split(r, n);
                auto merged = mergeTwoList(l, r);
                tail->next = merged.first;
                tail = merged.second;
            }
        }
        return dummy.next;
    }
};
