class Solution {
public:
    int maxArea(vector<int>& height)
    {
        int ans = 0;
        int l = 0, r = height.size() - 1;

        while (l < r) {
            ans = max(ans, (r - l) * min(height.at(l), height.at(r)));
            if (height.at(l) < height.at(r))
                l++;
            else
                r--;
        }

        return ans;
    }
};
