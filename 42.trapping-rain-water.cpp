#include <stack>
#include <vector>
using namespace std;

class Solution {
public:
    int trap(vector<int>& height) {
        int size = height.size();
        if (size <= 1) return 0;
        stack<int> stk;
        int water = 0;
        stk.push(height[0]);
        for (int i=1;i<size;i++) {
            if (height[i] <= stk.top()) stk.push(height[i]);
            else {
                int tmp = 0, step = 0, top;
                while (!stk.empty() && stk.top() < height[i]) {
                    top = stk.top();
                    tmp += height[i] - top;
                    step ++;
                    stk.pop();
                }
                if (!stk.empty() && stk.top() >= height[i]) {
                    water += tmp;
                    // stk.push(top);
                    while(step-- >= 0) stk.push(height[i]);
                } else {
                    water += tmp - step * (height[i] - top);
                    while(step-- > 0) stk.push(height[i]);
                    stk.push(height[i]);
                }
            }
        }
        return water;
    }
};
