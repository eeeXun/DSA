class Solution {
public:
    int combinationSum4(vector<int>& nums, int target)
    {
        sort(nums.begin(), nums.end());
        vector<unsigned int> dp(target + 1, 0);
        dp.at(0) = 1;
        for (int i = 1; i <= target; i++) {
            for (int n : nums) {
                if (n > i)
                    break;
                dp.at(i) += dp.at(i - n);
            }
        }
        return dp.at(target);
    }
};
