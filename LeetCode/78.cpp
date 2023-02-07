// ref
// https://ithelp.ithome.com.tw/articles/10276992
// https://leetcode.com/problems/subsets/solutions/27278/C++-RecursiveIterativeBit-Manipulation/
class Solution {
public:
    vector<vector<int>> subsets(vector<int>& nums)
    {
        vector<vector<int>> ans = { {} };

        for (auto i : nums) {
            int n = ans.size();
            for (int j = 0; j < n; j++) {
                ans.push_back(ans.at(j));
                ans.back().push_back(i);
            }
        }

        return ans;
    }
};
