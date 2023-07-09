class Solution {
private:
    void dfs(vector<string>& ans, string& tmp, int l_count, int r_count, int n)
    {
        if (l_count >= n) {
            for (int i = 0; i < l_count - r_count; i++) {
                tmp.push_back(')');
            }
            ans.push_back(tmp);
            for (int i = 0; i < l_count - r_count; i++) {
                tmp.pop_back();
            }
            return;
        }
        tmp.push_back('(');
        dfs(ans, tmp, l_count + 1, r_count, n);
        tmp.pop_back();
        if (l_count > r_count) {
            tmp.push_back(')');
            dfs(ans, tmp, l_count, r_count + 1, n);
            tmp.pop_back();
        }
    }

public:
    vector<string> generateParenthesis(int n)
    {
        vector<string> ans;
        string tmp;
        dfs(ans, tmp, 0, 0, n);

        return ans;
    }
};
