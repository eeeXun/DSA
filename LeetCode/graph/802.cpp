class Solution {
private:
    bool dfs(vector<vector<int>>& graph, vector<bool>& safe,
        vector<bool>& visited, int node)
    {
        if (visited.at(node)) {
            if (safe.at(node))
                return true;
            else
                return false;
        }
        bool safe_node = true;
        visited.at(node) = true;

        for (int i = 0; i < graph.at(node).size(); i++) {
            if (!dfs(graph, safe, visited, graph.at(node).at(i)))
                safe_node = false;
        }

        if (!safe_node)
            return false;
        safe.at(node) = true;
        return true;
    }

public:
    vector<int> eventualSafeNodes(vector<vector<int>>& graph)
    {
        vector<bool> safe(graph.size(), false);
        vector<bool> visited(graph.size(), false);
        vector<int> ans;

        for (int i = 0; i < graph.size(); i++) {
            dfs(graph, safe, visited, i);
        }
        for (int i = 0; i < graph.size(); i++) {
            if (safe.at(i))
                ans.push_back(i);
        }
        return ans;
    }
};
