#include <climits>

class Solution {
private:
    const int NOT_FOUND = 0;
    const int NOT_EXISTED = -1;
public:
    string minWindow(string s, string t) {
        int dict[CHAR_MAX+1], window[CHAR_MAX+1];
        memset(dict, NOT_EXISTED, sizeof(dict));
        memset(window, NOT_EXISTED, sizeof(window));
        for (int i=0;i<t.size();i++) {
            dict[t[i]] = (dict[t[i]] == NOT_EXISTED ? 1 : dict[t[i]]+1);
            window[t[i]] = NOT_FOUND;
        } 
        int left = 0, cnt = 0;
        int minStart = -1, minLen = INT_MAX;
        for (int right=0;right<s.size();right++) {
            char chr = s[right];
            if (dict[chr] == NOT_EXISTED) continue;
            
            if (window[chr] < dict[chr]) cnt ++;
            window[chr] ++;

            if (cnt >= t.size()) {
                char chl = s[left];
                while (window[chl] == NOT_EXISTED || window[chl] > dict[chl]) {
                    if (dict[chl] != NOT_EXISTED) {
                        if (window[chl] <= dict[chl]) cnt --;
                        window[chl] --;
                    }
                    chl = s[++left];
                }
                if (right - left + 1 < minLen) {
                    minStart = left;
                    minLen = right - left + 1;
                }
            }
        }
        string win = "";
        if (minStart >= 0 && minLen <= s.size())
            win = s.substr(minStart, minLen);
        return win;
    }
};
