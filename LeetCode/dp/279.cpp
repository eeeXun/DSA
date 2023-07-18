class Solution {
private:
    vector<int> sq_num;

public:
    Solution()
    {
        for (int i = 1; i < 100; i++) {
            sq_num.push_back(i * i);
        }
    }
    int numSquares(int n)
    {
        vector<int> dp(n + 1, INT_MAX);
        dp.at(0) = 0;
        for (int i = 0; i < sq_num.size() && sq_num.at(i) <= n; i++) {
            for (int j = sq_num.at(i); j <= n; j++) {
                dp.at(j) = min(dp.at(j - sq_num.at(i)) + 1, dp.at(j));
            }
        }
        return dp.at(n);
    }
};
