class Solution {
public:
    int findLengthOfLCIS(vector<int>& nums)
    {
        int ans = 1, current = 1;
        for (int i = 1; i < nums.size(); i++) {
            if (nums.at(i) <= nums.at(i - 1)) {
                current++;
                ans = max(ans, current);
            } else {
                current = 1;
            }
        }

        return ans;
    }
};
