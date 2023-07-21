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
    vector<int> findRedundantConnection(vector<vector<int>>& edges)
    {
        vector<int> root(edges.size() + 1, -1);
        for (auto edge : edges) {
            int p1 = find(root, edge.at(0));
            int p2 = find(root, edge.at(1));
            if (p1 == p2)
                return edge;
            root.at(p1) = p2;
        }
        return {};
    }
};
