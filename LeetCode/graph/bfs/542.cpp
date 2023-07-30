class Solution {
public:
    vector<vector<int>> updateMatrix(vector<vector<int>>& mat)
    {
        int x, y;
        int dirs[4][2] = { { -1, 0 }, { 1, 0 }, { 0, -1 }, { 0, 1 } };
        queue<pair<int, int>> q;
        pair<int, int> p;

        for (int i = 0; i < mat.size(); i++) {
            for (int j = 0; j < mat.at(i).size(); j++) {
                if (mat.at(i).at(j) == 0)
                    q.push({ i, j });
                else
                    mat.at(i).at(j) = INT_MAX;
            }
        }
        while (!q.empty()) {
            p = q.front();
            q.pop();
            for (int i = 0; i < 4; i++) {
                x = p.first + dirs[i][0];
                y = p.second + dirs[i][1];
                if (x < 0 || y < 0 || x >= mat.size()
                    || y >= mat.at(p.first).size())
                    continue;
                if (mat.at(x).at(y) < mat.at(p.first).at(p.second) + 1)
                    continue;
                mat.at(x).at(y) = mat.at(p.first).at(p.second) + 1;
                q.push({ x, y });
            }
        }

        return mat;
    }
};
