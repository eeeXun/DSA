class Solution {
public:
    int change(int amount, vector<int>& coins)
    {
        if (amount == 0)
            return 1;
        vector<int> dp(amount + 1, 0);

        for (int coin : coins) {
            if (coin > amount)
                continue;
            dp.at(coin)++;
            for (int i = coin; i <= amount; i++) {
                dp.at(i) += dp.at(i - coin);
            }
        }

        return dp.at(amount);
    }
};
