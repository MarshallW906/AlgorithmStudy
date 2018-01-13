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
    TreeNode *left;
    TreeNode *right;
    TreeNode(int x) : val(x), left(NULL), right(NULL) {}
};

class Solution {
    map<int, int> freq;

   public:
    vector<int> findFrequentTreeSum(TreeNode *root) {
        helper(root);
        vector<int> ret;
        int maxcnt = 0, maxsum = 0;
        for (auto &it : freq) {
            if (it.second > maxcnt) {
                ret.clear();
                // ret.resize(0);
                maxsum = it.first;
                maxcnt = it.second;
                ret.push_back(it.first);
            } else if (it.second == maxcnt) {
                ret.push_back(it.first);
            }
        }
        return ret;
    }
    int helper(TreeNode *root) {
        if (!root) return 0;
        if (root->left) root->val += helper(root->left);
        if (root->right) root->val += helper(root->right);
        freq[root->val]++;
        return root->val;
    }
};