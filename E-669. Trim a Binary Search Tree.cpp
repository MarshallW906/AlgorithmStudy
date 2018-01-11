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
    TreeNode* trimBST(TreeNode* root, int L, int R, bool top = true) {
        if (!root) return NULL;
        root->left = trimBST(root->left, L, R, false);
        root->right = trimBST(root->right, L, R, false);
        if (root->val >= L && root->val <= R) return root;
        TreeNode* retAfterTrim = root->val < L ? root->right : root->left;
        if (!top) delete root;
        return retAfterTrim;
        /** Memory leak because it didn't free the abandoned node
        if (!root) return NULL;
        if (root->val < L) return trimBST(root->right, L, R);
        if (root->val > R) return trimBST(root->left, L, R);
        root->left = trimBST(root->left, L, R);
        root->right = trimBST(root->right, L, R);
        return root;
        */
    }
};
