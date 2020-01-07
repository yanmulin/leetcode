#include <assert.h>
#include <string>
#include <vector>
using namespace std;
class Solution {
private:
    string mapping(char digit) {
        switch (digit) {
            case '2': return "abc";
            case '3': return "def";
            case '4': return "ghi";
            case '5': return "jkl";
            case '6': return "mno";
            case '7': return "pqrs";
            case '8': return "tuv";
            case '9': return "wxyz";
            default: assert(false);
        }
    }
public:
    vector<string> letterCombinations(string digits) {
        int size = digits.size();
        if (size == 0) return {};
        vector<string> res;
        string s = mapping(digits[0]);
        for (int k=0;k<s.size();k++)
                res.push_back({s[k]});
        for (int i=1;i<size;i++) {
            string s = mapping(digits[i]);
            vector<string> copy = res;
            res.clear();
            for (int j=0;j<copy.size();j++) {
                for (int k=0;k<s.size();k++)
                    res.push_back(copy[j] + s[k]);
            }
        }
        return res;
    }
};
