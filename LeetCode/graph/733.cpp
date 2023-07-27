class Solution {
private:
    void dfs(vector<vector<int>>& image, int sr, int sc, int color, int orig)
    {
        if (sr < 0 || sc < 0 || sr >= image.size() || sc >= image.at(0).size()
            || image.at(sr).at(sc) == color || image.at(sr).at(sc) != orig)
            return;
        image.at(sr).at(sc) = color;
        dfs(image, sr - 1, sc, color, orig);
        dfs(image, sr + 1, sc, color, orig);
        dfs(image, sr, sc - 1, color, orig);
        dfs(image, sr, sc + 1, color, orig);
    }

public:
    vector<vector<int>> floodFill(
        vector<vector<int>>& image, int sr, int sc, int color)
    {
        dfs(image, sr, sc, color, image.at(sr).at(sc));
        return image;
    }
};
