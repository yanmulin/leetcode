class Solution {
    bool match(char sc, char pc) {
        if (pc == '.') return true;
        else if (sc == pc) return true;
        return false;
    }
public:
    bool isMatch(string s, string p) {
        int ssz = s.size(), psz = p.size();
        bool m[ssz+1][psz+1];
        m[0][0] = true;
        for (int i=1;i<=ssz;i++)
            m[i][0] = false;
        for (int i=1;i<=psz;i++) 
            m[0][i] = i % 2 ? false : p[i-1] == '*' && m[0][i-2];
        for (int i=1;i<=ssz;i++) {
            for (int j=1;j<=psz;j++) {
                if (p[j-1] == '*' && m[i][j-1]) {
                    m[i][j] = true;
                }else if (p[j-1] == '*' && j > 1 && m[i][j-2]) {
                    m[i][j] = true;
                } else if (p[j-1] == '*' && j > 1 && (m[i-1][j-1] || m[i-1][j]) && match(s[i-1], p[j-2])) {
                    m[i][j] = true;
                } else if (p[j-1] != '*' && m[i-1][j-1] && match(s[i-1], p[j-1])) {
                    m[i][j] = true;
                } else {
                    m[i][j] = false;
                }
            }
        }
        return m[ssz][psz];
    }
};
