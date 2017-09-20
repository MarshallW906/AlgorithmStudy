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
    TreeNode* constructMaximumBinaryTree(vector<int>& nums) {
        if (nums.size() == 0) return NULL;

        int maxIdx = 0;
        for (int i = 0; i < nums.size(); i++) {
            if (nums[maxIdx] < nums[i]) maxIdx = i;
        }
        TreeNode* root = new TreeNode(nums[maxIdx]);

        // left
        vector<int> leftNums;
        for (int i = 0; i < maxIdx; i++) leftNums.push_back(nums[i]);
        root->left = constructMaximumBinaryTree(leftNums);

        // right
        vector<int> rightNums;
        for (int i = maxIdx + 1; i < nums.size(); i++) rightNums.push_back(nums[i]);
        root->right = constructMaximumBinaryTree(rightNums);

        return root;
    }
};