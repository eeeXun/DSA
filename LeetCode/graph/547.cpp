class Solution {
private:
    void dfs(vector<vector<int>>& isConnected, vector<bool>& visited, int node)
    {
        visited.at(node) = true;
        for (int i = 0; i < isConnected.size(); i++) {
            if (visited.at(i))
                continue;
            if (isConnected.at(node).at(i) == 1)
                dfs(isConnected, visited, i);
        }
    }

public:
    int findCircleNum(vector<vector<int>>& isConnected)
    {
        int ans = 0;
        vector<bool> visited(isConnected.size(), false);
        for (int i = 0; i < isConnected.size(); i++) {
            if (visited.at(i))
                continue;
            dfs(isConnected, visited, i);
            ans++;
        }

        return ans;
    }
};
