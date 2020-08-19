class Solution {
public:
    bool isPalindrome(string s) {
        int n = s.size();
        if (n == 0) return true;
        int l = 0, r = n - 1;
        while (l < r) {
            while (!isalnum(s[l]) && l < r) l ++;
            while (!isalnum(s[r]) && r > l) r --;
            if (tolower(s[l++]) != tolower(s[r--])) return false;
        }
        return true;
    } 
};
