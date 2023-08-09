class Solution {
public:
    int findNumberOfLIS(vector<int>& nums)
    {
        int ans = 1, max_len = 1;
        vector<int> dp(nums.size(), 1), cnt(nums.size(), 1);

        for (int i = 1; i < nums.size(); i++) {
            for (int j = 0; j < i; j++) {
                if (nums.at(i) <= nums.at(j))
                    continue;
                if (dp.at(i) == dp.at(j) + 1)
                    cnt.at(i) += cnt.at(j);
                else if (dp.at(i) <= dp.at(j)) {
                    dp.at(i) = dp.at(j) + 1;
                    cnt.at(i) = cnt.at(j);
                }
            }
            if (dp.at(i) == max_len)
                ans += cnt.at(i);
            else if (dp.at(i) > max_len) {
                max_len = dp.at(i);
                ans = cnt.at(i);
            }
        }

        return ans;
    }
};
