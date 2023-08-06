class Solution {
public:
    int findLongestChain(vector<vector<int>>& pairs)
    {
        int ans = 1;
        vector<int> dp(pairs.size(), 1);
        sort(pairs.begin(), pairs.end(),
            [](vector<int>& a, vector<int>& b) { return a.at(0) < b.at(0); });

        for (int i = 1; i < pairs.size(); i++) {
            for (int j = 0; j < i; j++) {
                if (pairs.at(j).at(1) < pairs.at(i).at(0)
                    && dp.at(i) <= dp.at(j)) {
                    dp.at(i) = dp.at(j) + 1;
                }
            }
            ans = max(ans, dp.at(i));
        }

        return ans;
    }
};
