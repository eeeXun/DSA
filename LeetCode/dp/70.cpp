class Solution {
private:
    int ans[45 + 1];

public:
    Solution()
    {
        ans[1] = 1;
        ans[2] = 2;
        for (int i = 3; i <= 45; i++) {
            ans[i] = ans[i - 1] + ans[i - 2];
        }
    }
    int climbStairs(int n) { return ans[n]; }
};
