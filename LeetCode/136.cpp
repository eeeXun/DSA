class Solution {
public:
    int singleNumber(vector<int>& nums)
    {
        map<int, int> data;
        int result;
        for (auto i : nums) {
            if (data.find(i) == data.end())
                data[i] = 1;
            else
                data[i]++;
        }
        for (auto it : data) {
            if (it.second == 1)
                result = it.first;
        }
        return result;
    }
};
