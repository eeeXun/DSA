class Solution {
public:
    int lengthOfLongestSubstring(string s)
    {
        int ans = 0;
        int left = 0, right = 0;
        set<char> container;

        while (right < s.length()) {
            if (container.find(s.at(right)) != container.end()) {
                container.erase(s.at(left));
                left++;
                continue;
            }
            container.insert(s.at(right));
            right++;
            ans = max(ans, right - left);
        }

        return ans;
    }
};
