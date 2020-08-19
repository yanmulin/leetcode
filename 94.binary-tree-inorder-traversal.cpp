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
public:
    vector<int> inorderTraversal(TreeNode* root) {
        stack<TreeNode*> stk;
        vector<int> result;
        while (!stk.empty() || root != NULL) {
            if (root == NULL) {
                root = stk.top();
                stk.pop();
                result.push_back(root->val);
                root = root->right;
            } else {
                stk.push(root);
                root = root->left;
            }
        }
        return result;
    }
};
