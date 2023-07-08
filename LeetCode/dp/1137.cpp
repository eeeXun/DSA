class Solution {
public:
    int tribonacci(int n)
    {
        int ppp = 0, pp = 1, p = 1, ans;
        if (n == 0)
            return 0;
        if (n == 1 || n == 2)
            return 1;
        for (int i = 3; i <= n; i++) {
            ans = ppp + pp + p;
            ppp = pp;
            pp = p;
            p = ans;
        }
        return ans;
    }
};
