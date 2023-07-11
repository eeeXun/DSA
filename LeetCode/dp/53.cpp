class Solution {
public:
    int maxSubArray(vector<int>& nums)
    {
        int ans = 1 << 31, tmp = 0;
        for (int i = 0; i < nums.size(); i++) {
            tmp += nums.at(i);
            if (tmp > ans)
                ans = tmp;
            if (tmp < 0)
                tmp = 0;
        }

        return ans;
    }
};
