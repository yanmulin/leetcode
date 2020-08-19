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
    void traversalIteratively(TreeNode* root, vector<int>& result) {
        if (!root) return;
        TreeNode *pn = root;
        stack<TreeNode*> stk;
        while (!stk.empty() || pn) {
            if (pn) {
                result.push_back(pn->val);
                stk.push(pn);
                pn = pn->left;
            } else {
                pn = stk.top(); stk.pop();
                pn = pn->right;
            }
        }
    }
    void traversalRecursively(TreeNode* root, vector<int>& result) {
        if (!root) return;
        result.push_back(root->val);
        traversalRecursively(root->left, result);
        traversalRecursively(root->right, result);
    }
public:
    vector<int> preorderTraversal(TreeNode* root) {
        vector<int> result;
        // traversalRecursively(root, result);
        traversalIteratively(root, result);
        return result;
    }
};
