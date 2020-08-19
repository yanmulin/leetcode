class Solution {
public:
    int mySqrt(int x) {
        if (x <= 1) return x;
        int low = 0, high = x;
        while (low <= high) {
            int mid = low + (high - low) / 2;
            if (mid > x / mid) high = mid - 1;
            else low = mid + 1;
        }
        return low - 1;
    }
};
