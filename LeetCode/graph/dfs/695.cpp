class Solution {
private:
    void dfs(vector<vector<int>>& grid, int i, int j, int& area)
    {
        if (i < 0 || j < 0 || i >= grid.size() || j >= grid.at(i).size()
            || grid.at(i).at(j) == 0)
            return;
        grid.at(i).at(j) = 0;
        area++;
        dfs(grid, i - 1, j, area);
        dfs(grid, i + 1, j, area);
        dfs(grid, i, j - 1, area);
        dfs(grid, i, j + 1, area);
    }

public:
    int maxAreaOfIsland(vector<vector<int>>& grid)
    {
        int ans = 0, tmp;
        for (int i = 0; i < grid.size(); i++) {
            for (int j = 0; j < grid.at(i).size(); j++) {
                if (grid.at(i).at(j) == 1) {
                    tmp = 0;
                    dfs(grid, i, j, tmp);
                    ans = max(ans, tmp);
                }
            }
        }
        return ans;
    }
};
