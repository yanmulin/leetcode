#define MAX(a, b) ((a)>(b)?(a):(b))

class Solution {
public:
    int longestValidParentheses(string s) {
        int ssz = s.size();
        if (ssz <= 1) return 0;
        stack<int> stk;
        int start = 0, max = 0;
        for (int i=0;i<ssz;i++) {
            if (s[i] == ')' && stk.empty())
                start = i + 1;
            else if (s[i] == '(') stk.push(i);
            else if (s[i] == ')') {
                stk.pop();
                if (stk.empty()) max = MAX(max, i - start + 1);
                else max = MAX(max, i - stk.top());
            }
        }
        return max;
    }
};
