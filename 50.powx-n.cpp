#define ABS(x) ((x)>0?(x):-(x))

class Solution {
private:
    bool equal(double x, double y) {
        static const double delta = 1e-6;
        return ABS(x - y) < delta;
    }
    double helper(double x, unsigned n) {
        if (n == 1) return x;
        double res = helper(x, n >> 1);
        return (n & 1 ? x : 1) * res * res;
    }
public:
    double myPow(double x, int n) {
        if (n == 0) return 1;
        if (equal(x, 0.0)) return 0;
        if (equal(x, 1.0)) return 1.0;
        if (equal(x, -1.0)) return n % 2 == 1 ? -1.0 : 1.0;
        long long ln = n;
        unsigned exp = ABS(ln);
        double res = helper(x, exp);
        return n > 0 ? res : (1.0 / res);
    }
};
