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
    void recoverTree(TreeNode* root) {
        pre = first = second = NULL;
        inorder(root);
        if (first && second)
            swap(first->val, second->val);
    }
private:
    TreeNode *pre, *first, *second;
    void inorder(TreeNode* root) {
        if (!root) return;
        inorder(root->left);
        if (pre && pre->val > root->val) {
            if (!first) first = pre;
            second = root;
        }
        pre = root;
        inorder(root->right);
    }
};
