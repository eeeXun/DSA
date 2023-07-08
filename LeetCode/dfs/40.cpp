class Solution {
private:
    void dfs(vector<vector<int>>& ans, vector<int>& tmp, vector<int> candidates,
        int start, int target)
    {
        if (target < 0)
            return;
        else if (target == 0)
            ans.push_back(tmp);
        else {
            for (int i = start; i < candidates.size(); i++) {
                if (i > start && candidates.at(i - 1) == candidates.at(i))
                    continue;
                tmp.push_back(candidates.at(i));
                dfs(ans, tmp, candidates, i + 1, target - candidates.at(i));
                tmp.pop_back();
            }
        }
    };

public:
    vector<vector<int>> combinationSum2(vector<int>& candidates, int target)
    {
        vector<vector<int>> ans;
        vector<int> tmp;
        sort(candidates.begin(), candidates.end());
        dfs(ans, tmp, candidates, 0, target);
        return ans;
    }
};
