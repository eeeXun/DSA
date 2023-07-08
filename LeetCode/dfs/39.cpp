class Solution {
private:
    void dfs(vector<vector<int>>& ans, vector<int>& tmp, vector<int> candidates,
        int target, int start)
    {
        if (target < 0)
            return;
        else if (target == 0)
            ans.push_back(tmp);
        else {
            for (int i = start; i < candidates.size(); i++) {
                tmp.push_back(candidates.at(i));
                dfs(ans, tmp, candidates, target - candidates.at(i), i);
                tmp.pop_back();
            }
        }
    }

public:
    vector<vector<int>> combinationSum(vector<int>& candidates, int target)
    {
        vector<vector<int>> ans;
        vector<int> tmp;
        dfs(ans, tmp, candidates, target, 0);
        return ans;
    }
};
