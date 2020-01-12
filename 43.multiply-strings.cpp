#include <string>
#include <iostream>

using namespace std;

class Solution {
private:
    string digitMutiply(int digit, const string &num) {
        int sz = num.size(), carry = 0;
        string res = "";
        for (int i=sz-1;i>=0;i--) {
            int tmp = (num[i] - '0') * digit + carry;
            res = char(tmp % 10 + '0') + res;
            carry = tmp / 10;
        }
        if (carry > 0) res = char(carry + '0') + res;
        return res;
    }
    string add(const string &op1, const string &op2) {
        int sz1 = op1.size(), sz2 = op2.size();
        int i = sz1 - 1, j = sz2 - 1;
        int carry = 0;
        string result = "";
        while (i >= 0 && j >= 0) {
            int sum = (op1[i] - '0') + (op2[j] - '0') + carry;
            result = char(sum % 10 + '0') + result;
            carry = sum / 10;
            i--;
            j--;
        }
        while (i >= 0) {
            int sum = (op1[i] - '0') + carry;
            result = char(sum % 10 + '0') + result;
            carry = sum / 10;
            i--;
        }
        while (j >= 0) {
            int sum = (op2[j] - '0') + carry;
            result = char(sum % 10 + '0') + result;
            carry = sum / 10;
            j--;
        }
        if (carry > 0) result = char(carry + '0') + result;
        return result;
    }

public:
    string multiply(string num1, string num2) {
        const string &op1 = num1.size() < num2.size() ? num1 : num2;
        const string &op2 = num1.size() < num2.size() ? num2 : num1;
        if (op1 == "0") return "0";
        int sz1 = op1.size(), sz2 = op2.size();
        string res = "";
        for (int i=0;i<sz1;i++) {
            res += '0';
            string m = digitMutiply(op1[i] - '0', op2);
            // cout << op1[i] << " * " << op2 << " = " << m << endl;
            // cout << res << " + " << m << " = ";
            res = add(res, m);
            // cout << res << endl;
        }
        return res;
    }
};
