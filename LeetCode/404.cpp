/**
 * Definition for a binary tree node.
 * struct TreeNode {
 *     int val;
 *     TreeNode *left;
 *     TreeNode *right;
 *     TreeNode() : val(0), left(nullptr), right(nullptr) {}
 *     TreeNode(int x) : val(x), left(nullptr), right(nullptr) {}
 *     TreeNode(int x, TreeNode *left, TreeNode *right) : val(x), left(left),
 * right(right) {}
 * };
 */
class Solution {
private:
    int sum;
    void helper(TreeNode* root)
    {
        if (!root->left && !root->right)
            return;
        if (root->left && !root->left->left && !root->left->right) {
            sum += root->left->val;
        } else if (root->left) {
            helper(root->left);
        }
        if (root->right)
            helper(root->right);
    }

public:
    int sumOfLeftLeaves(TreeNode* root)
    {
        helper(root);
        return sum;
    }
};
