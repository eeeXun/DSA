class Solution {
public:
    int orangesRotting(vector<vector<int>>& grid)
    {
        int ans = 0;
        int x, y;
        int m = grid.size(), n = grid.at(0).size();
        int dirs[4][2] = { { -1, 0 }, { 1, 0 }, { 0, -1 }, { 0, 1 } };
        pair<int, int> p;
        queue<pair<int, int>> q;

        for (int i = 0; i < m; i++) {
            for (int j = 0; j < n; j++) {
                switch (grid.at(i).at(j)) {
                case 0:
                    grid.at(i).at(j) = -1;
                    break;
                case 1:
                    grid.at(i).at(j) = INT_MAX;
                    break;
                case 2:
                    grid.at(i).at(j) = 0;
                    q.push({ i, j });
                    break;
                }
            }
        }
        while (!q.empty()) {
            p = q.front();
            q.pop();
            for (int i = 0; i < 4; i++) {
                x = p.first + dirs[i][0];
                y = p.second + dirs[i][1];
                if (x < 0 || y < 0 || x >= m || y >= n)
                    continue;
                if (grid.at(x).at(y) <= 0
                    || grid.at(x).at(y) <= grid.at(p.first).at(p.second) + 1)
                    continue;
                grid.at(x).at(y) = grid.at(p.first).at(p.second) + 1;
                q.push({ x, y });
                ans = max(ans, grid.at(x).at(y));
            }
        }
        for (int i = 0; i < m; i++) {
            for (int j = 0; j < n; j++) {
                if (grid.at(i).at(j) == INT_MAX)
                    return -1;
            }
        }
        return ans;
    }
};
