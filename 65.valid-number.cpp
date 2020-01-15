// / *[+-]?\d+(\.\d+)?(e\d+)?/
class Solution {
public:
    bool isNumber(string s) {
        int sz = s.size();
        if (sz == 0) return false;
        int i = 0;
        while (isspace(s[i])) i++;
        if (s[i] == '+' || s[i] == '-') i++;
        if (s[i] != '.' && !isdigit(s[i])) return false;
        while (isdigit(s[i])) i++;
        if (s[i] == '.') {
            i++;
            if((i == 1 || !isdigit(s[i-2])) && !isdigit(s[i])) return false;
            while (isdigit(s[i])) i++;
        }
        if (s[i] == 'e') {
            i++;
            if (s[i] == '-' || s[i] == '+') i++;
            if(!isdigit(s[i])) return false;
            while (isdigit(s[i])) i++;
        }
        while(isspace(s[i])) i++;
        return i == sz;
    }
};
