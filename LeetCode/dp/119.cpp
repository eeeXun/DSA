class Solution {
public:
    vector<int> getRow(int rowIndex)
    {
        vector<int> p;
        for (int i = 0; i <= rowIndex; i++) {
            vector<int> ans(i + 1);
            ans.at(0) = 1;
            ans.at(i) = 1;
            for (int j = 1; j < i; j++) {
                ans.at(j) = p.at(j - 1) + p.at(j);
            }
            p = ans;
        }
        return p;
    }
};
