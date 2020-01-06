#define ABS(x) ((x)>0?(x):(-x))
class Solution {
public:
    int reverse(int x) {
        if (x == INT_MIN) return 0;
        int sign = x > 0 ? 1 : -1;
        x = ABS(x);
        if (x < 10) return x * sign;
        long long unsigned a = 0;
        while (x != 0) {
            a = a * 10 + x % 10;
            x /= 10;
            if (a >> 31 > 0) return 0;
        }
        return int(a) * sign;
    }
};
