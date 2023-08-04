class Solution {
public:
    bool possibleBipartition(int n, vector<vector<int>>& dislikes)
    {
        int tmp;
        map<int, vector<int>> dis;
        vector<unsigned char> colors(n + 1, 0);
        queue<int> q;

        for (vector<int> dislike : dislikes) {
            dis[dislike.at(0)].push_back(dislike.at(1));
            dis[dislike.at(1)].push_back(dislike.at(0));
        }

        for (auto d_pair : dis) {
            if (colors.at(d_pair.first) != 0)
                continue;
            colors.at(d_pair.first) = 1;
            q.push(d_pair.first);
            while (!q.empty()) {
                tmp = q.front();
                q.pop();
                for (int d : dis[tmp]) {
                    if (colors.at(tmp) == colors.at(d))
                        return false;
                    if (colors.at(d) == 0) {
                        colors.at(d) = -1 * colors.at(tmp);
                        q.push(d);
                    }
                }
            }
        }
        return true;
    }
};
