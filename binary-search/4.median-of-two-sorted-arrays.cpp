class Solution {
private:
    double simpleMedian(const vector<int> &nums) {
        int n = nums.size();
        assert(n > 0);
        if (n % 2 == 0) return (nums[n / 2 - 1] + nums[n / 2]) / 2.0;
        else return nums[n/2];
    }
public:
    double findMedianSortedArrays(vector<int>& nums1, vector<int>& nums2) {
        size_t n1 = nums1.size(), n2 = nums2.size();
        if (n1 > n2)  return findMedianSortedArrays(nums2, nums1);
        int low = 0, high = n1 - 1, k = (n1 + n2 + 1) / 2;
        while (low <= high) {
            int m1 = low + (high - low) / 2, m2 = k - m1;
            if (nums1[m1] > nums2[m2-1]) high = m1 - 1;
            else low = m1 + 1;
        }

        int m1 = low, m2 = k - low;
        int first = max(m1 > 0 ? nums1[m1-1] : INT_MIN, m2 > 0 ? nums2[m2-1] : INT_MIN);
        if ((n1 + n2) % 2 == 1) return first;
        int second = min(m1 < n1 ? nums1[m1] : INT_MAX, m2 < n2 ? nums2[m2] : INT_MAX);
        return (first + second) * 0.5;
    }
};
