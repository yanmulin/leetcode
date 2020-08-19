class Solution {
public:
    int minEatingSpeed(vector<int>& piles, int H) {
        int low = 1, high = 1e9;
        while (low <= high) {
            int mid = low + (high - low) / 2;
            unsigned long long h = 0;
            for (int p: piles)
                h += (p + mid - 1) / mid;
            if (h <= H) high = mid - 1;
            else low = mid + 1;
        }
        return low;
    }
};
