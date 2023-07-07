class Solution {
private:
    void dfs(vector<vector<int>>& ans, vector<int>& nums, vector<int>& tmp,
        vector<bool>& visited, int len, int depth)
    {
        if (depth >= len) {
            ans.push_back(tmp);
            return;
        }
        for (int i = 0; i < len; i++) {
            if (visited.at(i))
                continue;
            tmp.push_back(nums.at(i));
            visited.at(i) = true;
            dfs(ans, nums, tmp, visited, len, depth + 1);
            visited.at(i) = false;
            tmp.pop_back();
        }
    }

public:
    vector<vector<int>> permute(vector<int>& nums)
    {
        vector<vector<int>> ans;
        vector<int> tmp;
        vector<bool> visited(nums.size(), false);
        dfs(ans, nums, tmp, visited, nums.size(), 0);

        return ans;
    }
};
