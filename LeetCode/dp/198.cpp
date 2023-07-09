class Solution {
public:
    int rob(vector<int>& nums)
    {
        int size = nums.size();
        if (size == 1)
            return nums.at(0);
        if (size == 2)
            return max(nums.at(0), nums.at(1));
        int max_pp = 0, max_p = nums.at(0), max_c = nums.at(1);
        int tmp;
        for (int i = 2; i < size; i++) {
            tmp = max({ max_c, nums.at(i) + max_p, nums.at(i) + max_pp });
            max_pp = max_p;
            max_p = max_c;
            max_c = tmp;
        }
        return max_c;
    }
};
