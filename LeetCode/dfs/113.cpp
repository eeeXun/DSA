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
    void dfs(TreeNode* root, vector<vector<int>>& ans, vector<int>& tmp,
        int targetSum, int sum)
    {
        if (!root)
            return;
        sum += root->val;
        tmp.push_back(root->val);
        if (!root->left && !root->right) {
            if (sum == targetSum)
                ans.push_back(tmp);
            tmp.pop_back();
            return;
        }
        dfs(root->left, ans, tmp, targetSum, sum);
        dfs(root->right, ans, tmp, targetSum, sum);
        tmp.pop_back();
    }

public:
    vector<vector<int>> pathSum(TreeNode* root, int targetSum)
    {
        vector<vector<int>> ans;
        vector<int> tmp;
        dfs(root, ans, tmp, targetSum, 0);

        return ans;
    }
};
