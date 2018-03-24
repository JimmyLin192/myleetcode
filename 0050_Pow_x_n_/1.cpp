class Solution {
public:
    // log(n) time and O(1) space
    double myPow(double x, int n) {
        double ans = 1.0;
        if (n == 0) {
            return ans;
        }
        if (x == 0) {
            return 0;
        } else if (x == 1.0) {
            return 1.0; 
        }
        long pow = n;
        if (pow < 0) {
            x = 1.0 / x;
            pow = -pow;
        }
        while (pow) {
            if (pow % 2) {
                ans *= x;
            }
            pow /= 2;
            x *= x;
        }
        return ans;
    }
};
