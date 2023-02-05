class Solution {
public:
    double myPow(double x, int n)
    {
        if (x == 0) {
            return 0;
        } else if (n == 0) {
            return 1;
        } else {
            if (n == 1) {
                return x;
            } else if (n == -1) {
                return 1.0 / x;
            } else {
                double div2 = myPow(x, n / 2);
                if (n % 2 == 1) {
                    x = x * div2 * div2;
                } else if (n % 2 == 0) {
                    x = div2 * div2;
                } else {
                    x = div2 * div2 / x;
                }
            }
        }
        return x;
    }
};
