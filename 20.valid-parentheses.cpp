class Solution {
private:
    bool match(char l, char r) {
        if (l == '(' && r == ')') return true;
        if (l == '{' && r == '}') return true;
        if (l == '[' && r == ']') return true;
        return false;
    }
public:
    bool isValid(string s) {
        int size = s.size();
        if (size == 0) return true;
        if (size % 2) return false;
        stack<char> stk;
        for (int i=0;i<size;i++) {
            if (s[i] == '(' || s[i] == '[' || s[i] == '{') {
                stk.push(s[i]);
            } else if (s[i] == ')' || s[i] == ']' || s[i] == '}') {
                if (stk.size() == 0) return false;
                char c = stk.top();
                stk.pop();
                if (!match(c, s[i])) return false;
            }
        }
        if (stk.size() > 0) return false;
        return true;
    }
};
