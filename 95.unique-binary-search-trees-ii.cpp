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
    vector<TreeNode*> generateTreesRecursively(int low, int high) {
        if (low > high) return {nullptr};
        vector<TreeNode*> result;
        for (int i=low;i<=high;i++) {
            vector<TreeNode*> lefts = generateTreesRecursively(low, i-1);
            vector<TreeNode*> rights = generateTreesRecursively(i+1, high);
            for (int j=0;j<lefts.size();j++) {
                for (int k=0;k<rights.size();k++) {
                    TreeNode* node = new TreeNode(i);
                    node->left = lefts[j];
                    node->right = rights[k];
                    result.push_back(node);
                }
            }
        }
        return result;
    }
public:
    vector<TreeNode*> generateTrees(int n) {
        if (n == 0) return {};
        return generateTreesRecursively(1, n);
    }
};
