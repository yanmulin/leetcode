class Solution {
public:
    string countAndSay(int n) {
        string base = "1";
        if (n == 1) return base;
        while (--n > 0) {
            string cpy = base;
            base = "";
            int c = 1, sz = cpy.size();
            for (int i=1;i<sz;i++) {
                if (cpy[i] == cpy[i-1]) {
                    c ++;
                } else {
                    base += to_string(c) + cpy[i-1];
                    c = 1;
                }
            }
            base += to_string(c) + cpy[sz-1];
        }
        return base;
    }
};
