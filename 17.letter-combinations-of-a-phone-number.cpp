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
        vector<string> p = mapping(digits[0]);
        vector<string> rp = p;
        for (int i=1;i<size;i++) {
            p.clear();
            vector<string> v = mapping(digits[i]);
            int psz = rp.size(), vsz = v.size();
            for (int j=0;j<psz;j++) {
                for (int k=0;k<vsz;k++) 
                    p.push_back(rp[j] + v[k]);
            }
            rp = p;
        }
        return p;
    }
};
