class Solution {
private:
    bool recurse(string s1, string s2) {
        if (s1.size() != s2.size()) return false;
        if (s1.size() == 0 || s2.size() == 0) return false;
        if (s1 == s2) return true;

        string ss1 = s1, ss2 = s2;
        sort(ss1.begin(), ss1.end());
        sort(ss2.begin(), ss2.end());
        if (ss1 != ss2) return false;

        for (int i=1;i<s1.size();i++) {
            if (recurse(s1.substr(0, i), s2.substr(s2.size()-i, i)) &&
                recurse(s1.substr(i, s1.size()-i), s2.substr(0, s2.size()-i)))
                return true;
            if (recurse(s1.substr(0, i), s2.substr(0, i)) &&
                recurse(s1.substr(i, s1.size()-i), s2.substr(i, s2.size()-i)))
                return true;
        }
        return false;
    }
public:
    bool isScramble(string s1, string s2) {
        return recurse(s1, s2);
    }
};
