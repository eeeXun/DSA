class Solution {
public:
    bool canPartition(vector<int>& nums)
    {
        int sum = accumulate(nums.begin(), nums.end(), 0);
        if (sum % 2 != 0)
            return false;

        int target = sum / 2;
        vector<bool> dp(target + 1, false);
        dp.at(0) = true;
        for (int i = 0; i < nums.size(); i++) {
            for (int j = target; j >= 0; j--) {
                if (dp.at(j) && j + nums.at(i) <= target) {
                    if (j + nums.at(i) == target)
                        return true;
                    dp.at(j + nums.at(i)) = true;
                }
            }
        }
        return false;
    }
};
