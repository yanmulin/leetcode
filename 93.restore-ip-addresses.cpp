class Solution {
private:
    bool isValid(const string &s) {
        int sz = s.size(), i;
        if (sz == 0 || sz > 3) return false;
        if (s[0] == '0' && sz != 1) return false;
        for (i=0;i<sz&&isdigit(s[i]);i++);
        if (i != sz) return false;
        if (atoi(s.c_str()) > 255) return false;
        return true;
    }
    void restoreIpAddressRecurse(const string &s, int start, int level, const string &solution, vector<string> &results) {
        if (level > 4) return;
        if (start >= s.size() && level == 4) {
            results.push_back(solution);
            return;
        }
        for (int i=1;i<=3 && start+i<=s.size();i++) {
            string sub = s.substr(start, i);
            if (!isValid(sub)) continue;
            if (solution.empty())
                restoreIpAddressRecurse(s, start+i, level+1, sub, results);
            else restoreIpAddressRecurse(s, start+i, level+1, solution + '.' + sub, results);
        }
    }
public:
    vector<string> restoreIpAddresses(string s) {
        int sz = s.size();
        if (sz == 0) return {};
        string solution;
        vector<string> results;
        restoreIpAddressRecurse(s, 0, 0, solution, results);
        return results;
    }
};
