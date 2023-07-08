class Solution {
private:
    void dfs(vector<vector<int>>& ans, vector<int>& tmp, int n, int k,
        int count, int index)
    {
        if (count == k) {
            ans.push_back(tmp);
            return;
        }
        for (int i = index; i <= n; i++) {
            tmp.push_back(i);
            dfs(ans, tmp, n, k, count + 1, i + 1);
            tmp.pop_back();
        }
    }

public:
    vector<vector<int>> combine(int n, int k)
    {
        vector<vector<int>> ans;
        vector<int> tmp;
        dfs(ans, tmp, n, k, 0, 1);
        return ans;
    }
};
