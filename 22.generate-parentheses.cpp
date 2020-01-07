class Solution {
    vector<string> generateParenthesisRecurse(int left, int n) {
        if (n == 0 && left == 0) return {""};
        vector<string> res;
        if (left > 0) {
            auto v = generateParenthesisRecurse(left - 1, n);
            int vsz = v.size();
            for (int i=0;i<vsz;i++) res.push_back(')' + v[i]);
        }
        if (n > 0) {
            auto v = generateParenthesisRecurse(left + 1, n - 1);
            int vsz = v.size();
            for (int i=0;i<vsz;i++) res.push_back('(' + v[i]);
        }
        return res;
    }
public:
    vector<string> generateParenthesis(int n) {
        return generateParenthesisRecurse(0, n);
    }
};
