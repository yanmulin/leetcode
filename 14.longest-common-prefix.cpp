#define MIN(a, b) ((a)<(b)?(a):(b))
class Solution {
public:
    string longestCommonPrefix(vector<string>& strs) {
        int size = strs.size();
        if (size == 0) return "";
        else if (size == 1) return strs[0];
        int minSize = strs[0].size();
        for (int i=1;i<size;i++) 
            minSize = MIN(strs[i].size(), minSize);
        int len;
        for (len=0;len<minSize;len++) {
            char ch = strs[0][len];
            int j;
            for (j=1;j<size;j++) {
                if(strs[j][len] != ch) break;
            }
            if (j != size) break;
        }
        return strs[0].substr(0, len);

    }
};
