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
    void traversalRecursively(TreeNode* root, vector<int> &result) {
        if (!root) return;
        traversalRecursively(root->left, result);
        result.push_back(root->val);
        traversalRecursively(root->right, result);
    }
    void traversalIteratively(TreeNode* root, vector<int> &result) {
        if (!root) return;
        TreeNode *pn = root;
        stack<TreeNode*> stk;
        while (!stk.empty() || pn) {
            if (pn) {
                stk.push(pn);
                pn = pn->left;
            } else {
                pn = stk.top(); stk.pop();
                result.push_back(pn->val);
                pn = pn->right;
            }
        }
    }
public:
    vector<int> inorderTraversal(TreeNode* root) {
        vector<int> result;
        // traversalRecursively(root, result);
        traversalIteratively(root, result);
        return result;
    }
};
