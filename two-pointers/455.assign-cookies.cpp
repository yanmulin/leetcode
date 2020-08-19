class Solution {
public:
    int findContentChildren(vector<int>& g, vector<int>& s) {
        int gn = g.size(), sn = s.size();
        int i = 0, j = 0;
        sort(g.begin(), g.end());
        sort(s.begin(), s.end());
        while (i < gn) {
            while (j < sn && s[j] < g[i]) j++;
            if (j == sn) break;
            i ++;
            j ++;
        }
        return i;
    }
};
