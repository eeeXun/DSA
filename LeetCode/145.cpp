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
public:
    vector<int> result;
    vector<int> postorderTraversal(TreeNode* root)
    {
        result = {};

        if (root == nullptr) {
            return result;
        } else {
            helper(root->left, root->right, root);
            return result;
        }
    }
    void helper(TreeNode* left, TreeNode* right, TreeNode* root)
    {
        if (root == nullptr)
            return;
        if (left != nullptr) {
            helper(left->left, left->right, left);
        }
        if (right != nullptr) {
            helper(right->left, right->right, right);
        }
        result.push_back(root->val);
    }
};
