#include <map>
#include <vector>
#include <string>

using namespace std;

class Solution {
public:
    vector<int> findSubstring(string s, vector<string>& words) {
        if (words.size() == 0) return {};
        map<string, int> expected;
        for (auto it=words.begin();it!=words.end();it++) {
            if (expected.find(*it) == expected.end()) {
                expected[*it] = 1;
            } else expected[*it] ++;
        }

        vector<int> res;
        int ssz = s.size(), wcount = words.size(), wsz = words[0].size();
        for (int i=0;i<wsz;i++) {
            int winLeft = i;
            int count = 0;
            map<string, int> actual;
            for (int j=i;j<ssz;j+=wsz) {
                string word = s.substr(j, wsz);
                if (expected.find(word) == expected.end()) {
                    actual.clear();
                    winLeft = j + wsz;
                    count = 0;
                    continue;
                }
                if (actual.find(word) == actual.end()) {
                    actual[word] = 1;
                } else actual[word] ++;
                if (actual[word] > expected[word]) {
                    string tmp;
                    do {
                        tmp = s.substr(winLeft, wsz);
                        winLeft += wsz;
                        actual[tmp] --;
                        count --;
                    } while (tmp != word);
                }
                count ++;
                if (count == wcount) { // find one
                    res.push_back(winLeft);
                    string tmp = s.substr(winLeft, wsz);
                    actual[tmp] --;
                    winLeft += wsz;
                    count--;
                }
            }
        }

        return res;
    }
};
