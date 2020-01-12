class Solution {
public:
    vector<vector<string>> groupAnagrams(vector<string>& strs) {
        vector<vector<string>> res;
        map<string, int> m;
        int sz = strs.size();
        for (int i=0;i<sz;i++) {
            string word = strs[i];
            sort(word.begin(), word.end());
            if (m.find(word) == m.end()) {
                m[word] = res.size();
                res.push_back({strs[i]});
            } else {
                res[m[word]].push_back(strs[i]);
            }
        }
        return res;
    }
};
