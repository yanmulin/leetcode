class Solution {
private:
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
public:
    int maximalRectangle(vector<vector<char>>& matrix) {
        if (matrix.size() == 0) return 0;
        int n = matrix.size(), m = matrix[0].size();
        vector<vector<int>> heights(n, vector<int>(m));
        for (int i=0;i<m;i++) heights[0][i] = matrix[0][i] == '1' ? 1 : 0; 
        int maxArea = largestRectangleArea(heights[0]);
        for (int i=1;i<n;i++) {
            for (int j=0;j<m;j++) {
                heights[i][j] = matrix[i][j] == '0' ? 0 : heights[i-1][j] + 1;
            }
            int area = largestRectangleArea(heights[i]);
            if (area > maxArea) maxArea = area;
        }
        return maxArea;
    }
};
