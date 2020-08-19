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
    ListNode* mergeTwoLists(ListNode *l1, ListNode *l2) {
        ListNode dummy(0), *p = &dummy, *p1 = l1, *p2 = l2;
        while (p1 && p2) {
            if (p1->val > p2->val) swap(p1, p2);
            p->next = p1;
            p1 = p1->next;
            p = p->next;
        }
        if (p1) p->next = p1;
        if (p2) p->next = p2;
        return dummy.next;
    }
    ListNode* merge(const vector<ListNode*>& lists, int l, int r) {
        if (l >= r) return NULL;
        else if (l + 1 == r) return lists[l];
        else if (l + 2 == r) return mergeTwoLists(lists[l], lists[l+1]);
        int m = l + (r - l) / 2;
        ListNode *list1 = merge(lists, l, m);
        ListNode *list2 = merge(lists, m, r);
        return mergeTwoLists(list1, list2);
    }
public:
    ListNode* mergeKLists(vector<ListNode*>& lists) {
        return merge(lists, 0, lists.size());
    }
    // ListNode* mergeKLists(vector<ListNode*>& lists) {
    //     auto comp = [](ListNode *n1, ListNode *n2) { return n1->val > n2->val; };
    //     priority_queue<ListNode*, vector<ListNode*>, decltype(comp)> pq(comp);
    //     ListNode dummy(0), *tail = &dummy;
    //     for (auto node: lists) 
    //         if (node) pq.push(node);
    //     while (!pq.empty()) {
    //         tail->next = pq.top(); pq.pop();
    //         tail = tail->next;
    //         if (tail->next) pq.push(tail->next);
    //     }
    //     return dummy.next;
    // }
};
