class Solution {
public:
    bool isMatch(string s, string p) {
        int sz1 = p.size(), sz2 = s.size();
        bool m[sz1+1][sz2+1];
        m[0][0] = true;
        for (int i=1;i<=sz1;i++)
            m[i][0] = p[i-1] == '*' ? m[i-1][0] : false;
        for (int j=1;j<=sz2;j++) 
            m[0][j] = false;
        for (int i=1;i<=sz1;i++) {
            for (int j=1;j<=sz2;j++) {
                if (p[i-1] == '*') {
                    for (int k=0;k<=j;k++) {
                        m[i][j] = m[i-1][k];
                        if (m[i][j]) break;
                    }
                } else {
                    m[i][j] = (p[i-1] == s[j-1] || p[i-1] == '?') && m[i-1][j-1];
                }
            }
        }
        return m[sz1][sz2];
    }
};
