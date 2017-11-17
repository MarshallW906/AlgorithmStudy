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
    int findBottomLeftValue(TreeNode* root) {
        maxDepth = -1;
        findBottomLeftVal(root, 0);
        return leftVal;
    }
private:
    int maxDepth, leftVal;
    void findBottomLeftVal(TreeNode* root, int curDepth) {
        if (curDepth > maxDepth) {
            maxDepth++;
            leftVal = root->val;
        }
        if (root->left) findBottomLeftVal(root->left, curDepth + 1);
        if (root->right) findBottomLeftVal(root->right, curDepth + 1);
    }
};