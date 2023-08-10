class Solution {
public:
    int deleteAndEarn(vector<int>& nums)
    {
        int tmp, sum_c = 0, sum_p = 0;
        map<int, int> m;

        for (int i = 0; i < nums.size(); i++) {
            m[nums.at(i)]++;
        }

        for (int i = 0; i < m.size(); i++) {
            tmp = max(i * m[i] + sum_p, sum_c);
            sum_p = sum_c;
            sum_c = tmp;
        }

        return sum_c;
    }
};
