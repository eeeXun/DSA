class Solution {
public:
    bool isPalindrome(string s)
    {
        string alphastring;
        int len;
        for (int i = 0; i < s.length(); i++) {
            if (s.at(i) >= 'A' && s.at(i) <= 'Z')
                s.at(i) = s.at(i) + 32;
        }
        for (auto i : s) {
            if ((i >= 'a' && i <= 'z') || (i >= '0' && i <= '9'))
                alphastring += i;
        }
        len = alphastring.length();
        for (int i = 0; i < len; i++) {
            if (alphastring.at(i) != alphastring.at(len - 1 - i))
                return false;
        }
        return true;
    }
};
