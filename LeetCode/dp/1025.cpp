class Solution {
public:
    bool divisorGame(int n)
    {
        vector<bool> dp(n + 1, false);

        for (int i = 2; i <= n; i++) {
            for (int j = 1; j < i; j++) {
                if (i % j == 0 && !dp.at(i - j)) {
                    dp.at(i) = true;
                    break;
                }
            }
        }

        return dp.back();
    }
};
