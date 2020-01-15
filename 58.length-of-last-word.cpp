class Solution {
public:
    int lengthOfLastWord(string s) {
        int count = 0, sz = s.size();
        for (int i=0;i<sz;i++) {
            if (i > 0 && isalpha(s[i]) && isspace(s[i-1])) count = 0;
            if (isalpha(s[i])) count ++;
        }
        return count;
    }
};
