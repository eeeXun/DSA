class Solution {
public:
    int minSubArrayLen(int target, vector<int>& nums)
    {
        int ans = 0, sum = 0;
        int left = 0, right = 0;

        while (right < nums.size()) {
            sum += nums.at(right++);
            while (sum >= target && left < right) {
                sum -= nums.at(left);
                ans = ans == 0 ? right - left : min(ans, right - left);
                left++;
            }
        }

        return ans;
    }
};
