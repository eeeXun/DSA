class Solution {
public:
    int coinChange(vector<int>& coins, int amount)
    {
        vector<int> dp(amount + 1, -1);
        dp.at(0) = 0;
        for (int i = 0; i < coins.size(); i++) {
            for (int j = coins.at(i); j <= amount; j++) {
                if (dp.at(j - coins.at(i)) >= 0) {
                    if (dp.at(j) < 0)
                        dp.at(j) = dp.at(j - coins.at(i)) + 1;
                    else
                        dp.at(j) = min(dp.at(j - coins.at(i)) + 1, dp.at(j));
                }
            }
        }
        return dp.at(amount);
    }
};
