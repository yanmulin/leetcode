class Solution {
public:
    string addBinary(string a, string b) {
        string res = "";
        int i = a.size() - 1, j = b.size() - 1;
        int carry = 0;
        while (i >= 0 && j >= 0) {
            int sum = (a[i] - '0') + (b[j] - '0') + carry;
            carry = sum / 2;
            res = char(sum%2 + '0') + res;
            i--;
            j--;
        }
        while (i >= 0) {
            int sum = (a[i] - '0') + carry;
            carry = sum / 2;
            res = char(sum%2 + '0') + res;
            i--;
        }
        while (j >= 0) {
            int sum = (b[j] - '0') + carry;
            carry = sum / 2;
            res = char(sum%2 + '0') + res;
            j--;
        }
        if (carry > 0) res = char(carry + '0') + res;
        return res;
    }
};
