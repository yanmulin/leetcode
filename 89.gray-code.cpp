class Solution {
private:
    int toGray(int x) {
        return x ^ (x >> 1);
    }
public:
    vector<int> grayCode(int n) {
        int max = pow(2, n);
        vector<int> result;
        for (int i=0;i<max;i++) {
            result.push_back(toGray(i));
        }
        return result;
    }
};
