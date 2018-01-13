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
   public:
    TreeNode* invertTree(TreeNode* root) {
        if (!root) return NULL;
        TreeNode* tmpRight = root->right;
        root->right = invertTree(root->left);
        root->left = invertTree(tmpRight);
        return root;
    }

    TreeNode* invertTree_BFS(TreeNode* root) {
        if (!root) return NULL;
        queue<TreeNode*> q;
        q.push(root);
        while (!q.empty()) {
            TreeNode* nd = q.front();
            q.pop();
            TreeNode* tmpRight = nd->right;
            nd->right = nd->left;
            nd->left = tmpRight;
            if (nd->left) q.push(nd->left);
            if (nd->right) q.push(nd->right);
        }
        return root;
    }
};