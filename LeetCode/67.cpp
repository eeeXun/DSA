class Solution {
public:
    string addBinary(string a, string b)
    {
        bool carry = false;
        string ans;

        if (a.length() < b.length())
            swap(a, b);
        reverse(a.begin(), a.end());
        reverse(b.begin(), b.end());

        for (int i = 0; i < b.length(); i++) {
            ans.push_back(((a.at(i) - 48) ^ (b.at(i) - 48) ^ carry) + 48);
            if ((a.at(i) == '1' && b.at(i) == '1') || (a.at(i) == '1' && carry)
                || (b.at(i) == '1' && carry))
                carry = true;
            else
                carry = false;
        }
        for (int i = b.length(); i < a.length(); i++) {
            ans.push_back(((a.at(i) - 48) ^ carry) + 48);
            if (a.at(i) == '1' && carry)
                carry = true;
            else
                carry = false;
        }
        if (carry)
            ans.push_back('1');
        reverse(ans.begin(), ans.end());

        return ans;
    }
};
