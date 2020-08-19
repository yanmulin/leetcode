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
    bool isMirrorTree(TreeNode* p, TreeNode* q) {
        if (!p && !q) return true;
        if (!p || !q) return false;
        if (p->val != q->val) return false;
        return isMirrorTree(p->left, q->right) && isMirrorTree(p->right, q->left);
    }
public:
    bool isSymmetric(TreeNode* root) {
        if (!root) return true;
        else return isMirrorTree(root->left, root->right);
    }
};