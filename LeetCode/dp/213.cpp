class Solution {
public:
    int rob(vector<int>& nums)
    {
        int size = nums.size();
        if (size == 1)
            return nums.at(0);
        if (size == 2)
            return max(nums.at(0), nums.at(1));
        if (size == 3)
            return max({ nums.at(0), nums.at(1), nums.at(2) });
        // include first
        int if_max_pp = 0, if_max_p = nums.at(0), if_max_c = nums.at(1);
        int tmp;
        for (int i = 2; i < size - 1; i++) {
            tmp = max(
                { if_max_c, nums.at(i) + if_max_p, nums.at(i) + if_max_pp });
            if_max_pp = if_max_p;
            if_max_p = if_max_c;
            if_max_c = tmp;
        }
        // exclude first
        int ef_max_pp = 0, ef_max_p = 0, ef_max_c = nums.at(1);
        for (int i = 2; i < size; i++) {
            tmp = max(
                { ef_max_c, nums.at(i) + ef_max_p, nums.at(i) + ef_max_pp });
            ef_max_pp = ef_max_p;
            ef_max_p = ef_max_c;
            ef_max_c = tmp;
        }
        return max(if_max_c, ef_max_c);
    }
};
