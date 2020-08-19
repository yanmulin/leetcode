/**
 * Definition for a binary tree node.
 * struct TreeNode {
 *     int val;
 *     TreeNode *left;
 *     TreeNode *right;
 *     TreeNode(int x) : val(x), left(NULL), right(NULL) {}
 * };
 */
class Solution {
private:
    vector<int> traversalIteratively(TreeNode* root) {
        deque<int> ans;
        stack<TreeNode*> stk;
        TreeNode *cur;
        stk.push(root);
        while (!stk.empty()) {
            cur = stk.top(); stk.pop();
            ans.push_front(cur->val);
            if (cur->left) stk.push(cur->left);
            if (cur->right) stk.push(cur->right);
        }
        return {ans.begin(), ans.end()};
    }
    void traversalRecursively(TreeNode* root, vector<int>& result) {
        if (!root) return;
        traversalRecursively(root->left, result);
        traversalRecursively(root->right, result);
        result.push_back(root->val);
    }
public:
    vector<int> postorderTraversal(TreeNode* root) {
        // vector<int> result;
        // traversalRecursively(root, result);
        // return result;
        return traversalIteratively(root);
    }
};
