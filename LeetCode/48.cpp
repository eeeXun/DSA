class Solution {
public:
    void rotate(vector<vector<int>>& matrix)
    {
        int len = matrix.size();
        vector<vector<int>> tmp = matrix;
        for (int i = 0; i < len; i++) {
            for (int j = 0; j < len; j++) {
                matrix.at(j).at(len - i - 1) = tmp.at(i).at(j);
            }
        }
    }
};
