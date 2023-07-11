class Solution {
private:
    int ans;
    void dfs(vector<int>& nums, int target, int index, int sum)
    {
        if (index > nums.size() - 1) {
            if (sum == target)
                ans++;
            return;
        }
        dfs(nums, target, index + 1, sum + nums.at(index));
        dfs(nums, target, index + 1, sum - nums.at(index));
    }

public:
    int findTargetSumWays(vector<int>& nums, int target)
    {
        dfs(nums, target, 0, 0);
        return ans;
    }
};
