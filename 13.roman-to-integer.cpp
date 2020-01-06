class Solution {
private:
    static map<char, int> mapping;
public:
    int romanToInt(string s) {
        int size = s.size();
        int sum = 0;
        for (int i=0;i<size-1;i++) {
            int value = mapping[s[i]];
            int nextVal = mapping[s[i+1]];
            if (value < nextVal) sum -= value;
            else sum += value;
        }
        sum += mapping[s[size-1]];
        return sum;
    }
};

map<char, int> Solution::mapping = {
        {'I', 1},
        {'V', 5},
        {'X', 10},
        {'L', 50},
        {'C', 100},
        {'D', 500},
        {'M', 1000},
};