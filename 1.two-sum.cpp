#include <iostream>
#include <vector>
#include <algorithm>
using namespace::std;
class Solution {
private: 
    int bsearch(vector<int>& nums, int start, int target) {
        int end = nums.size() - 1;
        if (target < nums[start] || target > nums[end]) return -1;
        while (start <= end) {
            int mid = (start + end) / 2;
            if (nums[mid] == target) return mid;
            else if (target > nums[mid]) start = mid + 1;
            else end = mid - 1;
        }
         return -1;
    }
public:
    
    vector<int> twoSum(vector<int>& nums, int target) {
        if (nums.size() < 2) return {};

        vector<int> copy(nums);
        sort(copy.begin(), copy.end());

        int size = nums.size();
        int first, second;
        for (first=0;first<size-1;first++) {
            second = bsearch(copy, first+1, target - copy[first]);
            if (second >= 0) break;
        }
        if (second < 0) return {};

        vector<int> res;
        for (int j=0;j<size;j++) {
            if (nums[j] == copy[first]) res.push_back(j);
            else if (nums[j] == copy[second]) res.push_back(j);
            if (res.size() == 2) break;
        }
        return res;
    }
};
