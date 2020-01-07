#include <assert.h>
#include <string>
#include <vector>
using namespace std;
class Solution {
public:
    vector<string> letterCombinations(string digits) {
        vector<string> mapping = {"abc", "def", 
                                    "ghi", "jkl", "mno", 
                                    "pqrs", "tuv", "wxyz"};
        int size = digits.size();
        if (size == 0) return {};
        vector<string> res;
        string s = mapping[digits[0] - '2'];
        for (int k=0;k<s.size();k++)
                res.push_back({s[k]});
        for (int i=1;i<size;i++) {
            string s = mapping[digits[i] - '2'];
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
