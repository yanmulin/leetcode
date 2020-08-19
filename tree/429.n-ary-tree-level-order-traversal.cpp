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
private:
    void traverseRecursively(Node* root, int level, vector<vector<int>>& result) {
        if (!root) return;
        while (result.size() <= level) 
            result.push_back({});
        for (auto child: root->children)
            result[level].push_back(child->val);
        for (auto child: root->children) 
            traverseRecursively(child, level + 1, result);
    }
    void traverseIteratively(Node* root, vector<vector<int>>& result) {
        if (!root) return;
        queue<Node*> q;
        q.push_front(root);
        while (!q.empty()) {
            result.push_back({});
            int n = q.size();
            for (int i=0;i<n;i++) {
                Node *node = q.back(); q.pop_back();
                result.back().push_back(node->val); 
                for (auto child: node->children) 
                    q.push_front(child);
            }
        }
    }
public:
    vector<vector<int>> levelOrder(Node* root) {
        vector<vector<int>> result;
        // traverseRecursively(root, 0, result);
        traverseIteratively(root, result);
        return result;
    }
};
