class Solution {
public:
    vector<vector<int>> generate(int numRows)
    {
        vector<vector<int>> ans;
        for (int i = 0; i < numRows; i++) {
            vector<int> tmp(i + 1);
            tmp.at(0) = 1;
            tmp.at(i) = 1;
            for (int j = 1; j < i; j++) {
                tmp.at(j) = ans.at(i - 1).at(j - 1) + ans.at(i - 1).at(j);
            }
            ans.push_back(tmp);
        }
        return ans;
    }
};
