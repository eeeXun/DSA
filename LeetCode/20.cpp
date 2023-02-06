class Solution {
public:
    bool isValid(string s)
    {
        stack<char> data;
        for (auto i : s) {
            switch (i) {
            case '(':
            case '{':
            case '[':
                data.push(i);
                break;
            case ')':
                if (data.empty())
                    return false;
                if (data.top() != '(')
                    return false;
                data.pop();
                break;
            case '}':
                if (data.empty())
                    return false;
                if (data.top() != '{')
                    return false;
                data.pop();
                break;
            case ']':
                if (data.empty())
                    return false;
                if (data.top() != '[')
                    return false;
                data.pop();
                break;
            }
        }
        if (data.empty())
            return true;
        else
            return false;
    }
};
