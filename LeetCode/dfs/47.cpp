class Solution {
private:
    void dfs(vector<vector<int>>& ans, vector<int>& tmp, vector<int>& nums,
        vector<bool>& visited, int len, int depth)
    {
        if (depth == len) {
            ans.push_back(tmp);
            return;
        }
        for (int i = 0; i < len; i++) {
            if (visited.at(i)
                || (i > 0 && nums.at(i) == nums.at(i - 1)
                    && !visited.at(i - 1)))
                continue;
            tmp.push_back(nums.at(i));
            visited.at(i) = true;
            dfs(ans, tmp, nums, visited, len, depth + 1);
            visited.at(i) = false;
            tmp.pop_back();
        }
    }

public:
    vector<vector<int>> permuteUnique(vector<int>& nums)
    {
        vector<vector<int>> ans;
        vector<int> tmp;
        vector<bool> visited(nums.size(), false);
        sort(nums.begin(), nums.end());
        dfs(ans, tmp, nums, visited, nums.size(), 0);

        return ans;
    }
};
