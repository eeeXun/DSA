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
    int findCircleNum(vector<vector<int>>& isConnected)
    {
        int ans = isConnected.size();
        vector<int> root(isConnected.size(), -1);
        for (int i = 0; i < isConnected.size(); i++) {
            int p1 = find(root, i);
            for (int j = 0; j < isConnected.size(); j++) {
                if (j != i && isConnected.at(i).at(j)) {
                    int p2 = find(root, j);
                    if (p1 != p2) {
                        ans--;
                        root.at(p2) = p1;
                    }
                }
            }
        }
        return ans;
    }
};
