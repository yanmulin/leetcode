/*
// Definition for a Node.
class Node {
public:
    int val;
    vector<Node*> children;

    Node() {}

    Node(int _val) {
        val = _val;
    }

    Node(int _val, vector<Node*> _children) {
        val = _val;
        children = _children;
    }
};
*/


class Solution {
public:
    vector<int> preorder(Node* root) {
        if (!root) return {};
        stack<Node*> stk;
        vector<int> res;
        stk.push(root);
        while (!stk.empty()) {
            Node *node = stk.top(); stk.pop();
            vector<Node*> &children = node->children;
            res.push_back(node->val);
            for (int i=children.size()-1;i>=0;i--)
                stk.push(children[i]);
        }
        return res;
    }
};

