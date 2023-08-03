class Solution {
private:
    int find(vector<int>& root, int i)
    {
        while (root.at(i) != -1)
            i = root.at(i);
        return i;
    }

public:
    bool possibleBipartition(int n, vector<vector<int>>& dislikes)
    {
        vector<int> root(n + 1, -1);
        map<int, vector<int>> dis_map;
        for (auto dislike : dislikes) {
            dis_map[dislike.at(0)].push_back(dislike.at(1));
            dis_map[dislike.at(1)].push_back(dislike.at(0));
        }
        for (auto dis : dis_map) {
            int x = find(root, dis.first);
            int y = find(root, dis.second.at(0));
            if (x == y)
                return false;
            for (int i = 1; i < dis.second.size(); i++) {
                int z = find(root, dis.second.at(i));
                if (x == z)
                    return false;
                if (y == z)
                    continue;
                root.at(z) = y;
            }
        }
        return true;
    }
};
