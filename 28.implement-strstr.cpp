class Solution {
public:
    int strStr(string haystack, string needle) {
        int sz1 = haystack.size(), sz2 = needle.size();
        if (sz2 == 0) return 0;
        if (sz1 == 0) return -1;
        for (int i=0;i<sz1-sz2+1;i++) {
            int j;
            for (j=0;j<sz2&&haystack[i+j]==needle[j];j++);
            if (j == sz2) return i;
        }
        return -1;
    }
};
