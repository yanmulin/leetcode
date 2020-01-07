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
        vector<vector<string>> res = {{}, {}};
        string s = mapping[digits[0] - '2'];
        for (int k=0;k<s.size();k++)
                res[0].push_back({s[k]});
        for (int i=1;i<size;i++) {
            string s = mapping[digits[i] - '2'];
            res[i%2].clear();
            for (int j=0;j<res[(i-1)%2].size();j++) {
                for (int k=0;k<s.size();k++)
                    res[i%2].push_back(res[(i-1)%2][j] + s[k]);
            }
        }
        return res[(size-1)%2];
    }
};
