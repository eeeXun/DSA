class Solution {
public:
    vector<int> countBits(int n)
    {
        vector<int> dp(n + 1);
        dp.at(0) = 0;
        int prev_pow_2 = 0, next_pow_2 = 2;
        for (int i = 1; i <= n; i++) {
            if (i == next_pow_2) {
                dp.at(i) = 1;
                prev_pow_2 = next_pow_2;
                next_pow_2 *= 2;
            } else {
                dp.at(i) = dp.at(i - prev_pow_2) + 1;
            }
        }

        return dp;
    }
};
