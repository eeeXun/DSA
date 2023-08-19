class Solution {
public:
    int numTrees(int n)
    {
        vector<int> dp(n + 1, 0);
        dp.at(0) = 1;

        for (int i = 1; i <= n; i++) {
            for (int j = 1; j <= i; j++) {
                dp.at(i) += dp.at(j - 1) * dp.at(i - j);
            }
        }

        return dp.back();
    }
};
