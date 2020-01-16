class Solution {
public:
    vector<int> plusOne(vector<int>& digits) {
        int sz = digits.size();
        if (sz == 0) return digits;
        digits[sz-1] += 1;
        int i, carry = digits[sz-1] / 10;
        digits[sz-1] = digits[sz-1] % 10;
        for (i=sz-2;i>=0&&carry>0;i--) {
            digits[i] += carry;
            carry = digits[i] / 10;
            digits[i] = digits[i] % 10;
        }
        if (carry > 0) digits.insert(digits.begin(), carry);
        return digits;
    }
};
