#include "./stdc++.h"

using namespace std;

/**
 * Definition for a binary tree node.
 * struct TreeNode {
 *     int val;
 *     TreeNode *left;
 *     TreeNode *right;
 *     TreeNode(int x) : val(x), left(NULL), right(NULL) {}
 * };
 */

struct TreeNode {
    int val;
    TreeNode* left;
    TreeNode* right;
    TreeNode(int x) : val(x), left(NULL), right(NULL) {}
};

class Solution {
    vector<int> ret;

   public:
    vector<int> largestValues(TreeNode* root) {
        if (!root) return ret;
        helper(root, 0);
        return ret;
    }
    void helper(TreeNode* node, int cl) {
        if (!node) return;
        if (ret.size() < cl + 1)
            ret.push_back(node->val);
        else if (ret[cl] < node->val)
            ret[cl] = node->val;
        helper(node->left, cl + 1);
        helper(node->right, cl + 1);
    }
};
