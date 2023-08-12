class Solution {
public:
    int lastStoneWeight(vector<int>& stones)
    {
        int tmp;
        while (stones.size() > 1) {
            sort(stones.begin(), stones.end());
            tmp = stones.at(stones.size() - 1) - stones.at(stones.size() - 2);
            stones.pop_back();
            stones.pop_back();
            if (tmp > 0)
                stones.push_back(tmp);
        }
        if (stones.empty())
            return 0;
        return stones.at(0);
    }
};
