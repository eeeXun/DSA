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
    int makeConnected(int n, vector<vector<int>>& connections)
    {
        int redundant = 0, root_count = 0;
        vector<int> root(n, -1);
        for (auto connection : connections) {
            int p1 = find(root, connection.at(0));
            int p2 = find(root, connection.at(1));
            if (p1 != p2)
                root.at(p2) = p1;
            else
                redundant++;
        }
        for (auto r : root) {
            if (r == -1)
                root_count++;
        }
        if (redundant < (root_count - 1))
            return -1;

        return root_count - 1;
    }
};
