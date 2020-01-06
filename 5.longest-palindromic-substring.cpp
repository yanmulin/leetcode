// 动态规划: 寻找新字符与前面子串的组成Palindrome，与子串已知最大长度比较
#include <assert.h>
class Solution {
private:
    bool isPalindrome(string &s, int start, int end) {
        if (start == end) assert(false);
        int i = start, mid = (start + end) / 2, j = end; 
        if ((end - start) % 2 == 0) { // 个数奇数
            while (i<mid&&j>mid) {
                if (s[i++] != s[j--]) 
                    return false;
            }
        } else {
            while (i<=mid&&j>mid) {
                if (s[i++] != s[j--]) 
                    return false;
            }
        }
        return true;
    }

    int searchLongerPalindrome(string &s, int start, int end, int minLength) {
        for (int i=start;i<end-minLength+1;i++) {
            if (isPalindrome(s, i, end))
                return end - i + 1;
        }
        return 0;
    }

public:
    string longestPalindrome(string s) {
        int size = s.size();
        if (size <= 1) return s;
        int lens[size];
        int startIndex = 0;
        lens[0] = 1;

        for (int i=1;i<size;i++) {
            int len = searchLongerPalindrome(s, 0, i, lens[i-1]);
            if (lens[i-1] >= len) {
                lens[i] = lens[i-1];
            } else {
                startIndex = i - len + 1;
                lens[i] = len;
            }
        }

        return s.substr(startIndex, lens[size-1]);
    }
};
