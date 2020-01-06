// TopK问题： 归并
class Solution {
public:
    double findMedianSortedArrays(vector<int>& nums1, vector<int>& nums2) {
        int sz1 = nums1.size(), sz2 = nums2.size();
        int sz = (sz1 + sz2) / 2 + 1;
        int nums[sz];
        int i = 0, j = 0;
        for (int k = 0;k < sz;k++) {
            if (i >= sz1) nums[k] = nums2[j++];
            else if (j >= sz2) nums[k] = nums1[i++];
            else if (nums1[i] < nums2[j]) nums[k] = nums1[i++];
            else nums[k] = nums2[j++];
        }
        if ((sz1 + sz2) % 2 == 0) return (nums[sz - 1] + nums[sz - 2]) / 2.0;
        else return nums[sz - 1];
    }
};
