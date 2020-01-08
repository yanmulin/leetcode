class Solution {
public:
    int divide(int dividend, int divisor) {
        assert(divisor != 0);
        if (dividend == 0) return 0;
        if (divisor == 1) return dividend;
        if (divisor == -1) return dividend == INT_MIN ? INT_MAX : -dividend;

        int n;
        long long mdivisor = divisor;
        if (dividend > 0 && divisor > 0) {
            n = 1;
            while (dividend >= mdivisor) {
                dividend -= mdivisor;
                mdivisor += mdivisor;
                n += n;
            }
            while (dividend >= divisor) {
                dividend -= divisor;
                n += 1;
            }
            n --;
        } else if (dividend < 0 && divisor < 0) {
            n = 1;
            while (dividend <= mdivisor) {
                dividend -= mdivisor;
                mdivisor += mdivisor;
                n += n;
            }
            while (divisor != INT_MIN && dividend <= divisor) {
                dividend -= divisor;
                n += 1;
            }
            n --;
        } else if (dividend > 0 && divisor < 0) {
            n = -1;
            while (dividend >= -mdivisor) {
                dividend += mdivisor;
                mdivisor += mdivisor;
                n += n;
            }
            while (divisor != INT_MIN && dividend >= -divisor) {
                dividend += divisor;
                n -= 1;
            }
            n ++;
        } else if (dividend < 0 && divisor > 0) {
            n = -1;
            while (dividend <= -mdivisor) {
                dividend += mdivisor;
                mdivisor += mdivisor;
                n += n;
            }
            while (dividend <= -divisor) {
                dividend += divisor;
                n -= 1;
            }
            n ++;
        } else assert(false);
        return n;
    }
};
