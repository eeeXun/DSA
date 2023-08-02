class Solution {
public:
    int shortestPathBinaryMatrix(vector<vector<int>>& grid)
    {
        if (grid.at(0).at(0) == 1)
            return -1;
        int n = grid.size();
        int x, y;
        int dirs[8][2] = { { -1, -1 }, { -1, 0 }, { -1, 1 }, { 0, 1 }, { 1, 1 },
            { 1, 0 }, { 1, -1 }, { 0, -1 } };
        pair<int, int> p;
        queue<pair<int, int>> q;

        q.push({ 0, 0 });
        grid.at(0).at(0) = 1;
        while (!q.empty()) {
            p = q.front();
            q.pop();
            if (p.first == n - 1 && p.second == n - 1)
                return grid.at(p.first).at(p.second);
            for (int i = 0; i < 8; i++) {
                x = p.first + dirs[i][0];
                y = p.second + dirs[i][1];
                if (x < 0 || y < 0 || x >= n || y >= n)
                    continue;
                if (grid.at(x).at(y) > 0)
                    continue;
                grid.at(x).at(y) = grid.at(p.first).at(p.second) + 1;
                q.push({ x, y });
            }
        }
        return -1;
    }
};
