class Solution {
private:
    int find(vector<int>& root, int node)
    {
        while (root.at(node) != -1) {
            node = root.at(node);
        }
        return node;
    }

public:
    int removeStones(vector<vector<int>>& stones)
    {
        int ans = 0;
        vector<int> root(stones.size(), -1);
        for (int i = 0; i < stones.size(); i++) {
            int p1 = find(root, i);
            for (int j = i + 1; j < stones.size(); j++) {
                if (stones.at(i).at(0) == stones.at(j).at(0)
                    || stones.at(i).at(1) == stones.at(j).at(1)) {
                    int p2 = find(root, j);
                    if (p1 != p2) {
                        root.at(p2) = p1;
                    }
                }
            }
        }
        for (int i = 0; i < root.size(); i++) {
            if (root.at(i) != -1)
                ans++;
        }
        return ans;
    }
};
