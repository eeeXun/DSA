class Solution {
public:
    vector<int> largestDivisibleSubset(vector<int>& nums)
    {
        int max_index = 0, max_count = -1;
        vector<int> ans, dp(nums.size(), 1), prev(nums.size(), -1);
        sort(nums.begin(), nums.end());

        for (int i = 1; i < nums.size(); i++) {
            for (int j = 0; j < i; j++) {
                if (nums.at(i) % nums.at(j) == 0 && dp.at(i) <= dp.at(j)) {
                    dp.at(i) = dp.at(j) + 1;
                    prev.at(i) = j;
                    if (dp.at(i) > max_count) {
                        max_count = dp.at(i);
                        max_index = i;
                    }
                }
            }
        }

        while (max_index != -1) {
            ans.push_back(nums.at(max_index));
            max_index = prev.at(max_index);
        }

        return ans;
    }
};
