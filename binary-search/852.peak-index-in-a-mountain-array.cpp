class Solution {
public:
    int peakIndexInMountainArray(vector<int>& A) {
        size_t n = A.size();
        int low = 0, high = n - 1;
        while (low <= high) {
            int mid = low + (high - low) / 2;
            if (mid < n - 1 && A[mid] > A[mid + 1]) 
                high = mid - 1;
            else low = mid + 1;
        }
        return low;
    }
};
