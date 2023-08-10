class Solution {
public:
    int rob(vector<int>& nums)
    {
        int tmp, max_c = 0, max_p = 0;
        for (int i = 0; i < nums.size(); i++) {
            tmp = max(nums.at(i) + max_p, max_c);
            max_p = max_c;
            max_c = tmp;
        }

        return max_c;
    }
};
