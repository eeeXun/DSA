class Solution {
private:
    int dfs(int n, int headID, map<int, vector<int>>& subordinates,
        vector<int>& informTime, int time)
    {
        time += informTime.at(headID);
        int ans = time;
        for (auto subordinate : subordinates[headID]) {
            ans = max(ans, dfs(n, subordinate, subordinates, informTime, time));
        }

        return ans;
    }

public:
    int numOfMinutes(
        int n, int headID, vector<int>& manager, vector<int>& informTime)
    {
        map<int, vector<int>> subordinates;
        for (int i = 0; i < n; i++) {
            if (manager.at(i) >= 0)
                subordinates[manager.at(i)].push_back(i);
        }

        return dfs(n, headID, subordinates, informTime, 0);
    }
};
