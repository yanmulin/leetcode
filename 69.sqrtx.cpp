class Solution {
public:
    int mySqrt(int x) {
        if (x == 0) return 0;
        if (x == 1 || x == 2) return 1;
        int start = 1, end = x - 1;
        while (start < end) {
            long long mid = (start + end) / 2;
            long long m1 = mid * mid, m2 = (mid+1) * (mid+1);
            if (m1 <= x && m2 > x) return mid;
            else if (m1 > x) end = mid;
            else if (m2 <= x) start = mid;
        } 
        assert(false);
        return -1;
    }
};
