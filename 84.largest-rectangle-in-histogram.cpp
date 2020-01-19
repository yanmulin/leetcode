class Solution {
public:
    int largestRectangleArea(vector<int>& heights) {
        if (heights.size() == 0) return 0;
        stack<int> stk;
        heights.push_back(0);
        int maxArea = INT_MIN;
        for (int i=0;i<heights.size();i++) {
            int height = heights[i];
            while (!stk.empty() && heights[stk.top()] >= height) {
                int idx = stk.top();
                stk.pop();
                int area = heights[idx] * (stk.empty() ? i : i - 1 - stk.top());
                if (area > maxArea) maxArea = area;
            }
            stk.push(i);
        }
        return maxArea; 
    }
};
