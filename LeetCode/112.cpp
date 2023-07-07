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
    bool dfs(TreeNode* root, int targetSum, int sum, bool parentIsRoot)
    {
        if (!root) {
            if (sum == targetSum && !parentIsRoot)
                return true;
            else
                return false;
        }
        sum += root->val;
        if (dfs(root->left, targetSum, sum, root->left || root->right))
            return true;
        if (dfs(root->right, targetSum, sum, root->left || root->right))
            return true;
        return false;
    }

public:
    bool hasPathSum(TreeNode* root, int targetSum)
    {
        if (!root)
            return false;
        return dfs(root, targetSum, 0, root->left || root->right);
    }
};
