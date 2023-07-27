class Solution {
private:
    void dfs(
        vector<vector<int>>& grid, vector<vector<bool>>& visited, int i, int j)
    {
        if (i < 0 || j < 0 || i >= grid.size() || j >= grid.at(i).size()
            || visited.at(i).at(j) || grid.at(i).at(j) == 1)
            return;
        visited.at(i).at(j) = true;
        dfs(grid, visited, i - 1, j);
        dfs(grid, visited, i, j - 1);
        dfs(grid, visited, i + 1, j);
        dfs(grid, visited, i, j + 1);
    }

public:
    int closedIsland(vector<vector<int>>& grid)
    {
        int ans = 0;
        vector<vector<bool>> visited(
            grid.size(), vector<bool>(grid.at(0).size(), false));

        for (int i = 0; i < grid.size(); i++) {
            for (int j = 0; j < grid.at(i).size(); j++) {
                if (!visited.at(i).at(j)
                    && (i == 0 || i == grid.size() - 1 || j == 0
                        || j == grid.at(i).size() - 1)) {
                    if (grid.at(i).at(j) == 1)
                        visited.at(i).at(j) = true;
                    else
                        dfs(grid, visited, i, j);
                }
            }
        }

        for (int i = 1; i < grid.size() - 1; i++) {
            for (int j = 1; j < grid.at(i).size() - 1; j++) {
                if (!visited.at(i).at(j) && grid.at(i).at(j) == 0) {
                    dfs(grid, visited, i, j);
                    ans++;
                }
            }
        }

        return ans;
    }
};
