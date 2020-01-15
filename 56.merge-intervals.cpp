class Solution {
public:
    vector<vector<int>> merge(vector<vector<int>>& intervals) {
        int sz = intervals.size();
        if (sz <= 1) return intervals;
        sort(intervals.begin(), intervals.end(), [](const vector<int> &v1, const vector<int> &v2) {
            return v1[0] < v2[0];
        });

        vector<vector<int>> res;
        int min = intervals[0][0], max = intervals[0][1];
        for (int i=1;i<sz;i++) {
            if (intervals[i][0] <= max && intervals[i][1] >= max) 
                max = intervals[i][1];
            else if (intervals[i][0] > max) {
                res.push_back({min, max});
                min = intervals[i][0];
                max = intervals[i][1];
            }
        }
        res.push_back({min, max});
        return res;
    }
};
