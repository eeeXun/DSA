class Solution {
private:
    void dfs(vector<vector<int>>& ans, vector<int>& tmp, vector<int>& nums,
        int len, int depth, int index, int size)
    {
        if (depth >= len) {
            ans.push_back(tmp);
            return;
        }
        if (depth + (size - index) < len || index >= size)
            return;
        for (int i = index; i < size; i++) {
            if (i > index && nums.at(i) == nums.at(i - 1))
                continue;
            tmp.push_back(nums.at(i));
            dfs(ans, tmp, nums, len, depth + 1, i + 1, size);
            tmp.pop_back();
        }
    }

public:
    vector<vector<int>> subsetsWithDup(vector<int>& nums)
    {
        vector<vector<int>> ans;
        vector<int> tmp;
        sort(nums.begin(), nums.end());
        int size = nums.size();

        for (int i = 0; i <= size; i++) {
            dfs(ans, tmp, nums, i, 0, 0, size);
        }

        return ans;
    }
};
