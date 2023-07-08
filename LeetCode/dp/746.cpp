class Solution {
public:
    int minCostClimbingStairs(vector<int>& cost)
    {
        int pp = cost.at(0), p = cost.at(1), current = 0;
        for (int i = 2; i < cost.size(); i++) {
            current = min(pp, p) + cost.at(i);
            pp = p;
            p = current;
        }
        return min(pp, p);
    }
};
