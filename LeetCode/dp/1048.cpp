class Solution {
public:
    int longestStrChain(vector<string>& words)
    {
        int ans = 1;
        string tmp;
        map<string, int> dp;
        sort(words.begin(), words.end(),
            [](string& a, string& b) { return a.length() < b.length(); });

        for (string word : words) {
            dp[word] = 1;
            for (int i = 0; i < word.length(); i++) {
                tmp = word.substr(0, i) + word.substr(i + 1);
                if (dp.find(tmp) != dp.end()) {
                    dp[word] = max(dp[word], dp[tmp] + 1);
                    ans = max(ans, dp[word]);
                }
            }
        }

        return ans;
    }
};
