#include <assert.h>
#include <string>
#include <vector>
using namespace std;
class Solution {
private:
    vector<string> mapping(char digit) {
        switch (digit) {
            case '2': return {"a", "b", "c"};
            case '3': return {"d", "e", "f"};
            case '4': return {"g", "h", "i"};
            case '5': return {"j", "k", "l"};
            case '6': return {"m", "n", "o"};
            case '7': return {"p", "q", "r", "s"};
            case '8': return {"t", "u", "v"};
            case '9': return {"w", "x", "y", "z"};
            default: assert(false);
        }
    }
public:
    vector<string> letterCombinations(string digits) {
        int size = digits.size();
        if (size == 0) return {};
        vector<vector<string>> p;
        for (int i=size-1;i>=0;i--) p.push_back(mapping(digits[i]));
        while (p.size() > 1) {
            vector<string> v, v1, v2;
            v1 = p.back();
            p.pop_back();
            v2 = p.back();
            p.pop_back();
            int v1sz = v1.size(), v2sz = v2.size();
            for (int j=0;j<v1sz;j++) {
                for (int k=0;k<v2sz;k++) {
                    v.push_back(v1[j] + v2[k]);
                }
            }
            p.push_back(v);
        }
        return p.back();
    }
};
