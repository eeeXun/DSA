class Solution {
private:
    bool valid(vector<vector<int>>& graph, vector<unsigned char>& colors,
        int index, unsigned char color)
    {
        if (colors.at(index) != 0)
            return colors.at(index) == color;
        colors.at(index) = color;
        for (int i = 0; i < graph.at(index).size(); i++) {
            if (!valid(graph, colors, graph.at(index).at(i), -1 * color))
                return false;
        }
        return true;
    }

public:
    bool isBipartite(vector<vector<int>>& graph)
    {
        vector<unsigned char> colors(graph.size(), 0);
        for (int i = 0; i < graph.size(); i++) {
            if (colors.at(i) == 0 && !valid(graph, colors, i, 1))
                return false;
        }
        return true;
    }
};
