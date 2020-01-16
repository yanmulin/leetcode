class Solution {
public:
    vector<string> fullJustify(vector<string>& words, int maxWidth) {
        int wc = words.size();
        int len, start, end;
        len = start = end = 0;
        bool lastLine = false;
        vector<string> result;
        for (int i=0;i<wc;i++) {
            len += words[i].size();
            if (len + i - start > maxWidth || i == wc - 1) {
                if (len + i - start > maxWidth) {
                    len -= words[i].size();
                    end = i - 1;
                    lastLine = false;
                } else {
                    end = i;
                    lastLine = true;
                }

                int space, mspace, extra;
                space = maxWidth - len;
                if (lastLine || end == start) {
                    mspace = 1;
                    extra = 0;
                } else {
                    mspace = floor(space / (end - start));
                    extra = space - mspace * (end - start);
                }
                string line = words[start];
                for (int j=start+1;j<=end;j++) {
                    for (int k=mspace;k>0&&space>0;k--,space--) {
                        line += ' ';
                    }
                    if (j - start - 1 < extra) {
                        line += ' ';
                        space --;
                    }
                    line += words[j];
                }
                for (;space>0;space--) {
                    line += ' ';
                }

                result.push_back(line);
                start = i;
                i = end;
                len = 0;
            }
        }
        return result;
    }
};
