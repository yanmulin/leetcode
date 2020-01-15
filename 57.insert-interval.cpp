
class Solution {
private:
    bool intervalIntersect(const vector<int> &i1, const vector<int> &i2) {
        if (i1[0] > i2[1]) return false;
        if (i1[1] < i2[0]) return false;
        return true;
    }
public:
    vector<vector<int>> insert(vector<vector<int>>& intervals, vector<int>& newInterval) {
        int sz = intervals.size(), i;
        bool inserted = false;
        vector<vector<int>> res;
        for (i=0;i<sz;i++) {
            if (!inserted && intervals[i][0] > newInterval[1]) {
                res.push_back(newInterval);
                inserted = true;
            }
            if (!intervalIntersect(intervals[i], newInterval)) res.push_back(intervals[i]);
            else {
                newInterval[0] = min(intervals[i][0], newInterval[0]);
                newInterval[1] = max(intervals[i][1], newInterval[1]);
            }
        }
        if (!inserted) res.push_back(newInterval);
        return res;
    }
};
