// 解法一：反转数字
class Solution {
public:
    bool isPalindrome(int x) {
        if (x < 0) return false;
        if (x < 10) return true;
        int a = x;
        long long unsigned n = 0;
        while (x != 0) {
            n = n * 10 + x % 10;
            if (n >> 31 > 0) return false;
            x /= 10;
        }
        return int(n) == a;
    }
};
