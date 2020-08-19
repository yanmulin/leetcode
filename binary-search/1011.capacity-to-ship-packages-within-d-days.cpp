class Solution {
public:
    int shipWithinDays(vector<int>& weights, int D) {
        int low = *max_element(weights.begin(), weights.end()), high = 500 * 50000;
        while (low <= high) {
            int mid = low + (high - low) / 2;
            int d = 1, load = 0;
            for (int w: weights) {
                if (load + w > mid) {
                    load = w;
                    d++;
                } else load += w;
            }
            if (d <= D) high = mid - 1;
            else low = mid + 1;
        }
        return low;
    }
};
