class Solution {
public:
    bool containsNearbyDuplicate(vector<int>& nums, int k)
    {
        map<int, int> table;

        for (int i = 0; i < nums.size() && i <= k; i++) {
            table[nums.at(i)]++;
            if (table[nums.at(i)] > 1)
                return true;
        }
        for (int i = k + 1; i < nums.size(); i++) {
            table[nums.at(i - k - 1)]--;
            table[nums.at(i)]++;
            if (table[nums.at(i)] > 1)
                return true;
        }

        return false;
    }
};
