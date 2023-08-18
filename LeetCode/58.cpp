class Solution {
public:
    int lengthOfLastWord(string s)
    {
        int ans = 0;
        int start_index;

        for (int i = s.length() - 1; i >= 0; i--) {
            if (s.at(i) != ' ') {
                start_index = i;
                break;
            }
        }
        for (int i = start_index; i >= 0; i--) {
            if (s.at(i) == ' ')
                break;
            ans++;
        }

        return ans;
    }
};
