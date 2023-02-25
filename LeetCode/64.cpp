class Solution {
public:
    int minPathSum(vector<vector<int>>& grid)
    {
        int m = grid.size();
        int n = grid.at(0).size();
        vector<vector<int>> sum(m, vector<int>(n));
        sum.at(0).at(0) = grid.at(0).at(0);
        for (int i = 1; i < m; i++)
            sum.at(i).at(0) = sum.at(i - 1).at(0) + grid.at(i).at(0);
        for (int i = 1; i < n; i++)
            sum.at(0).at(i) = sum.at(0).at(i - 1) + grid.at(0).at(i);
        for (int i = 1; i < m; i++) {
            for (int j = 1; j < n; j++) {
                sum.at(i).at(j) = grid.at(i).at(j)
                    + min(sum.at(i - 1).at(j), sum.at(i).at(j - 1));
            }
        }
        return sum.at(m - 1).at(n - 1);
    }
};
