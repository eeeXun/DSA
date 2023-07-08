class Solution {
public:
    int fib(int n)
    {
        int ans;
        int pp = 0, p = 1;
        if (n == 0)
            return 0;
        if (n == 1)
            return 1;
        for (int i = 2; i <= n; i++) {
            ans = pp + p;
            pp = p;
            p = ans;
        }
        return ans;
    }
};
