class Solution {
public:
    int uniquePaths(int m, int n)
    {
        double ans = 1;
        if (m < n) {
            swap(m, n);
        }

        for (int i = m + n - 2; i > m; i--) {
            ans *= i;
        }
        for (int i = 2; i <= n; i++) {
            ans /= i;
        }

        return (int)ans;
    }
};
