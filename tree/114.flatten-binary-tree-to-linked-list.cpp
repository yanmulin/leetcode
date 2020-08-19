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
    TreeNode* flattenRecursively(TreeNode* root) {
        if (!root->right && !root->left) return root;
        if (!root->right) {
            root->right = root->left;
            root->left = NULL;
        }
        if (!root->left) return flattenRecursively(root->right);
        auto leftlast = flattenRecursively(root->left);
        auto rightmost = flattenRecursively(root->right);
        leftlast->right = root->right;
        root->right = root->left;
        root->left = nullptr;
        return rightmost;
    }
public:
    void flatten(TreeNode* root) {
        if (!root) return;
        flattenRecursively(root);
    }
};