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
    bool isValidBSTRecusively(TreeNode *root, long low, long high) {
        if (root == NULL) return true;
        if (root->val >= high || root->val <= low) return false;
        return isValidBSTRecusively(root->left, low, root->val) && 
                isValidBSTRecusively(root->right, root->val, high);
    }
public:
    bool isValidBST(TreeNode* root) {
        return isValidBSTRecusively(root, LONG_MIN, LONG_MAX);
    }
};
