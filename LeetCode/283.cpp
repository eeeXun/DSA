class Solution {
public:
    void moveZeroes(vector<int>& nums)
    {
        int count = 0;
        vector<int> tmp;
        for (auto i : nums) {
            if (i != 0)
                tmp.push_back(i);
            else
                count++;
        }
        nums = tmp;
        for (int i = 0; i < count; i++)
            nums.push_back(0);
    }
};
