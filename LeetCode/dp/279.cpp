class Solution {
public:
    int numSquares(int n)
    {
        int tmp;
        vector<int> dp(n + 1, INT_MAX);
        dp.at(0) = 0;
        for (int i = 1; i <= n; i++) {
            for (int j = 1; j < 100; j++) {
                tmp = j * j;
                if (tmp > i)
                    break;
                dp.at(i) = min(dp.at(i - tmp) + 1, dp.at(i));
            }
        }
        return dp.at(n);
    }
};
