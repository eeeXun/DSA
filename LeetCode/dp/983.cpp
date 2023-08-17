class Solution {
public:
    int mincostTickets(vector<int>& days, vector<int>& costs)
    {
        vector<int> dp(days.back() + 1, INT_MAX);
        dp.at(0) = 0;

        int day_index = 0;
        for (int i = 1; i <= days.back(); i++) {
            if (i != days.at(day_index)) {
                dp.at(i) = dp.at(i - 1);
                continue;
            }
            dp.at(i) = min({ dp.at(max(0, i - 1)) + costs.at(0),
                dp.at(max(0, i - 7)) + costs.at(1),
                dp.at(max(0, i - 30)) + costs.at(2) });
            day_index++;
        }

        return dp.back();
    }
};
