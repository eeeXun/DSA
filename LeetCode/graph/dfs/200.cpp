class Solution {
private:
    void dfs(vector<vector<char>>& grid, int i, int j)
    {
        if (i < 0 || j < 0 || i >= grid.size() || j >= grid.at(i).size()
            || grid.at(i).at(j) == '0')
            return;
        grid.at(i).at(j) = '0';
        dfs(grid, i - 1, j);
        dfs(grid, i + 1, j);
        dfs(grid, i, j - 1);
        dfs(grid, i, j + 1);
    }

public:
    int numIslands(vector<vector<char>>& grid)
    {
        int ans = 0;

        for (int i = 0; i < grid.size(); i++) {
            for (int j = 0; j < grid.at(i).size(); j++) {
                if (grid.at(i).at(j)=='1') {
                    dfs(grid, i, j);
                    ans++;
                }
            }
        }

        return ans;
    }
};
