class Solution {
public:
    void reverseString(vector<char>& s)
    {
        int len = s.size();
        for (int i = 0; i < len / 2; i++)
            swap(s.at(i), s.at(len - 1 - i));
    }
};
