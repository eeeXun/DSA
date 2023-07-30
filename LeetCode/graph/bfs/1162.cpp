class Solution {
public:
    int maxDistance(vector<vector<int>>& grid)
    {
        int ans = -1;
        int x, y;
        int dirs[4][2] = { { -1, 0 }, { 1, 0 }, { 0, -1 }, { 0, 1 } };
        pair<int, int> p;
        queue<pair<int, int>> q;

        for (int i = 0; i < grid.size(); i++) {
            for (int j = 0; j < grid.at(i).size(); j++) {
                if (grid.at(i).at(j) == 1) {
                    grid.at(i).at(j) = 0;
                    q.push({ i, j });
                } else {
                    grid.at(i).at(j) = INT_MAX;
                }
            }
        }
        while (!q.empty()) {
            p = q.front();
            q.pop();
            for (int i = 0; i < 4; i++) {
                x = p.first + dirs[i][0];
                y = p.second + dirs[i][1];
                if (x < 0 || y < 0 || x >= grid.size()
                    || y >= grid.at(x).size())
                    continue;
                if (grid.at(x).at(y) == 0
                    || grid.at(x).at(y) <= grid.at(p.first).at(p.second) + 1)
                    continue;
                grid.at(x).at(y) = grid.at(p.first).at(p.second) + 1;
                q.push({ x, y });
                ans = max(ans, grid.at(x).at(y));
            }
        }

        return ans;
    }
};
