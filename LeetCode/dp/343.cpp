class Solution {
public:
    int integerBreak(int n)
    {
        vector<int> dp(n + 1, 0);
        dp.at(1) = 1;
        for (int i = 2; i <= n; i++) {
            for (int j = 1; j <= i / 2; j++) {
                dp.at(i) = max(dp.at(i),
                    (dp.at(j) > j ? dp.at(j) : j)
                        * (dp.at(i - j) > (i - j) ? dp.at(i - j) : i - j));
            }
        }

        return dp.at(n);
    }
};
